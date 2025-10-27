<?php
/**
 * Database Setup Script
 * Run this file ONCE to create the database and users table
 * Access: http://localhost/your-project/setup_database.php
 */

// Load environment configuration
require_once 'config.php';

// Create connection without selecting database
$conn = new mysqli(DB_HOST, DB_USER, DB_PASS);

// Check connection
if ($conn->connect_error) {
    die("<div style='background: #fee; color: #c00; padding: 20px; border: 2px solid #c00; border-radius: 8px; margin: 20px; font-family: monospace;'>
        <strong>Connection failed:</strong> " . htmlspecialchars($conn->connect_error) . "<br><br>
        <strong>Please check:</strong><br>
        1. MySQL is running in XAMPP/WAMP<br>
        2. Database credentials in .env.local are correct
    </div>");
}

echo "<h2>Database Setup</h2>";
echo "<pre>";

// Create database
$sql = "CREATE DATABASE IF NOT EXISTS " . DB_NAME;
if ($conn->query($sql) === TRUE) {
    echo "✅ Database '" . DB_NAME . "' created successfully (or already exists)\n\n";
} else {
    echo "❌ Error creating database: " . $conn->error . "\n\n";
}

// Select database
$conn->select_db(DB_NAME);

// Create users table
$sql = "CREATE TABLE IF NOT EXISTS users (
    id INT(11) AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    full_name VARCHAR(100),
    email VARCHAR(100),
    role ENUM('admin', 'student', 'teacher') DEFAULT 'student',
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    last_login TIMESTAMP NULL,
    is_active TINYINT(1) DEFAULT 1
)";

if ($conn->query($sql) === TRUE) {
    echo "✅ Table 'users' created successfully (or already exists)\n\n";
} else {
    echo "❌ Error creating table: " . $conn->error . "\n\n";
}

// Insert demo users
$demo_users = [
    [
        'username' => 'admin',
        'password' => password_hash('admin123', PASSWORD_DEFAULT),
        'full_name' => 'Administrator',
        'email' => 'admin@javapractical.com',
        'role' => 'admin'
    ],
    [
        'username' => 'student',
        'password' => password_hash('student123', PASSWORD_DEFAULT),
        'full_name' => 'Demo Student',
        'email' => 'student@javapractical.com',
        'role' => 'student'
    ],
    [
        'username' => 'demo',
        'password' => password_hash('demo123', PASSWORD_DEFAULT),
        'full_name' => 'Demo User',
        'email' => 'demo@javapractical.com',
        'role' => 'student'
    ]
];

echo "Inserting demo users:\n";
foreach ($demo_users as $user) {
    // Check if user already exists
    $check = $conn->prepare("SELECT id FROM users WHERE username = ?");
    $check->bind_param("s", $user['username']);
    $check->execute();
    $result = $check->get_result();
    
    if ($result->num_rows > 0) {
        echo "⚠️  User '{$user['username']}' already exists - skipped\n";
    } else {
        // Insert new user
        $stmt = $conn->prepare("INSERT INTO users (username, password, full_name, email, role) VALUES (?, ?, ?, ?, ?)");
        $stmt->bind_param("sssss", 
            $user['username'], 
            $user['password'], 
            $user['full_name'], 
            $user['email'], 
            $user['role']
        );
        
        if ($stmt->execute()) {
            echo "✅ User '{$user['username']}' created successfully\n";
        } else {
            echo "❌ Error creating user '{$user['username']}': " . $stmt->error . "\n";
        }
        $stmt->close();
    }
    $check->close();
}

echo "\n";
echo "=" . str_repeat("=", 60) . "\n";
echo "DATABASE SETUP COMPLETED!\n";
echo "=" . str_repeat("=", 60) . "\n\n";

echo "Demo Credentials:\n";
echo "  👤 admin / admin123 (Admin)\n";
echo "  👤 student / student123 (Student)\n";
echo "  👤 demo / demo123 (Student)\n\n";

echo "⚠️  SECURITY: Delete this file after setup is complete!\n";
echo "</pre>";

$conn->close();
?>