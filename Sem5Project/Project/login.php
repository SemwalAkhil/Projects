<?php
/**
 * Login Page with Database Integration
 * Handles user authentication using MySQL database
 */

// Start session at the very beginning
session_start();

// Include database configuration
require_once 'config.php';

// Check if database is set up
function isDatabaseSetup() {
    $conn = @new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);
    
    if ($conn->connect_error) {
        return false;
    }
    
    // Check if users table exists
    $result = $conn->query("SHOW TABLES LIKE 'users'");
    $exists = ($result && $result->num_rows > 0);
    
    $conn->close();
    return $exists;
}

// Redirect to setup if database not ready
if (!isDatabaseSetup() && basename($_SERVER['PHP_SELF']) !== 'setup_database.php') {
    header("Location: " . BASE_PATH . "setup_database.php");
    exit();
}

// If already logged in, redirect to main page
if (isset($_SESSION['logged_in']) && $_SESSION['logged_in'] === true) {
    header("Location: " . BASE_PATH . "index.php");
    exit();
}

$error_message = '';
$success_message = '';

// Handle login form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $username = trim($_POST['username'] ?? '');
    $password = $_POST['password'] ?? '';
    
    // Validate input
    if (empty($username) || empty($password)) {
        $error_message = "Please enter both username and password.";
    } else {
        // Get database connection
        $conn = getDatabaseConnection();
        
        if ($conn === false) {
            $error_message = "Database connection failed. Please try again later.";
        } else {
            // Prepare SQL statement to prevent SQL injection
            $stmt = $conn->prepare("SELECT id, username, password, full_name, role, is_active FROM users WHERE username = ?");
            $stmt->bind_param("s", $username);
            $stmt->execute();
            $result = $stmt->get_result();
            
            if ($result->num_rows === 1) {
                $user = $result->fetch_assoc();
                
                // Check if account is active
                if ($user['is_active'] != 1) {
                    $error_message = "Your account has been deactivated. Please contact administrator.";
                }
                // Verify password
                elseif (password_verify($password, $user['password'])) {
                    // Successful login - Set session variables
                    $_SESSION['logged_in'] = true;
                    $_SESSION['user_id'] = $user['id'];
                    $_SESSION['username'] = $user['username'];
                    $_SESSION['full_name'] = $user['full_name'];
                    $_SESSION['role'] = $user['role'];
                    $_SESSION['login_time'] = time();
                    
                    // Update last login time
                    $update_stmt = $conn->prepare("UPDATE users SET last_login = NOW() WHERE id = ?");
                    $update_stmt->bind_param("i", $user['id']);
                    $update_stmt->execute();
                    $update_stmt->close();
                    
                    $success_message = "Login successful! Redirecting...";
                    
                    // Close connection before redirect
                    $stmt->close();
                    closeDatabaseConnection($conn);
                    
                    header("refresh:1;url=index.php");
                    exit();
                } else {
                    $error_message = "Invalid username or password.";
                }
            } else {
                $error_message = "Invalid username or password.";
            }
            
            $stmt->close();
            closeDatabaseConnection($conn);
        }
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="index.css">
    <link rel="icon" type="image/x-icon" href="logo.png">
    <title>Login - Java Practical</title>
</head>
<body>
    <div class="login-container">
        <div class="login-header">
            <h1>🔐 Login</h1>
            <p>Java Programming Portal</p>
        </div>

        <?php if ($error_message): ?>
            <div class="alert alert-error">
                <?php echo htmlspecialchars($error_message); ?>
            </div>
        <?php endif; ?>

        <?php if ($success_message): ?>
            <div class="alert alert-success">
                <?php echo htmlspecialchars($success_message); ?>
            </div>
        <?php endif; ?>

        <form method="POST" action="">
            <div class="form-group">
                <label for="username">Username</label>
                <input 
                    type="text" 
                    id="username" 
                    name="username" 
                    placeholder="Enter your username"
                    value="<?php echo htmlspecialchars($username ?? ''); ?>"
                    required
                    autofocus
                >
            </div>

            <div class="form-group">
                <label for="password">Password</label>
                <input 
                    type="password" 
                    id="password" 
                    name="password" 
                    placeholder="Enter your password"
                    required
                >
            </div>

            <button type="submit" class="btn-login">Login</button>
        </form>

        <div class="demo-credentials">
            <h3>Demo Credentials:</h3>
            <p>👤 admin / admin123</p>
            <p>👤 student / student123</p>
            <p>👤 demo / demo123</p>
        </div>
    </div>
</body>
</html>