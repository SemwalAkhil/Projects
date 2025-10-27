<?php
/**
 * Database Configuration File with .env.local Support
 * Loads database credentials from .env.local file
 */

/**
 * Load environment variables from .env.local file
 * @param string $file Path to the .env file
 * @return bool Success status
 */
// Detect if running through Ngrok
$isNgrok = (isset($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] === 'https') 
           || (strpos($_SERVER['HTTP_HOST'] ?? '', 'ngrok') !== false);

// Set base path based on environment
if ($isNgrok) {
    // When using Ngrok, use root-relative paths
    define('BASE_PATH', '/Project/');
    define('BASE_URL', 'https://' . $_SERVER['HTTP_HOST'] . BASE_PATH);
} else {
    // Local development
    define('BASE_PATH', '/Project/');
    define('BASE_URL', 'http://localhost' . BASE_PATH);
}

/**
 * Helper function to create proper URLs
 */
function url($path = '') {
    return BASE_URL . ltrim($path, '/');
}

function loadEnv($file = '.env.local') {
    if (!file_exists($file)) {
        // Fallback to .env if .env.local doesn't exist
        $file = '.env';
        if (!file_exists($file)) {
            error_log("Environment file not found: $file");
            return false;
        }
    }
    
    $lines = file($file, FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
    
    foreach ($lines as $line) {
        // Skip comments
        if (strpos(trim($line), '#') === 0) {
            continue;
        }
        
        // Parse key=value pairs
        if (strpos($line, '=') !== false) {
            list($key, $value) = explode('=', $line, 2);
            $key = trim($key);
            $value = trim($value);
            
            // Remove quotes if present
            $value = trim($value, '"\'');
            
            // Set in $_ENV and putenv for access
            $_ENV[$key] = $value;
            putenv("$key=$value");
        }
    }
    
    return true;
}

// Load environment variables
loadEnv();

// Database configuration constants
// Use environment variables with fallback defaults
if (!defined('DB_HOST')) {
    define('DB_HOST', getenv('DB_HOST') ?: 'localhost');
}
if (!defined('DB_USER')) {
    define('DB_USER', getenv('DB_USER') ?: 'root');
}
if (!defined('DB_PASS')) {
    define('DB_PASS', getenv('DB_PASS') ?: '');
}
if (!defined('DB_NAME')) {
    define('DB_NAME', getenv('DB_NAME') ?: 'java_practical');
}

// Optional application settings
if (!defined('APP_NAME')) {
    define('APP_NAME', getenv('APP_NAME') ?: 'Java Programming Portal');
}
if (!defined('APP_ENV')) {
    define('APP_ENV', getenv('APP_ENV') ?: 'development');
}
if (!defined('SESSION_LIFETIME')) {
    define('SESSION_LIFETIME', getenv('SESSION_LIFETIME') ?: 3600);
}

/**
 * Create database connection
 * @return mysqli|false Database connection object or false on failure
 */
function getDatabaseConnection() {
    $conn = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);
    
    // Check connection
    if ($conn->connect_error) {
        error_log("Database Connection Failed: " . $conn->connect_error);
        
        // Show user-friendly error in development mode
        if (APP_ENV === 'development') {
            die("<div style='background: #fee; color: #c00; padding: 20px; border: 2px solid #c00; border-radius: 8px; margin: 20px; font-family: monospace;'>
                <strong>Database Connection Error:</strong><br>
                " . htmlspecialchars($conn->connect_error) . "<br><br>
                <strong>Check:</strong><br>
                1. MySQL server is running (XAMPP/WAMP)<br>
                2. Database credentials in .env.local are correct<br>
                3. Database '" . DB_NAME . "' exists (run setup_database.php)
            </div>");
        }
        
        return false;
    }
    
    // Set charset to utf8mb4 for proper character encoding
    $conn->set_charset("utf8mb4");
    
    return $conn;
}

/**
 * Close database connection
 * @param mysqli $conn Database connection object
 */
function closeDatabaseConnection($conn) {
    if ($conn && !$conn->connect_error) {
        $conn->close();
    }
}

/**
 * Get environment variable value
 * @param string $key Environment variable key
 * @param mixed $default Default value if not found
 * @return mixed Environment variable value or default
 */
function env($key, $default = null) {
    $value = getenv($key);
    return $value !== false ? $value : $default;
}
?>