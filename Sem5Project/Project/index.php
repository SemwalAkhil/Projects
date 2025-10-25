<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="index.css">
    <link rel="icon" type="image/x-icon" href="logo.png">
    <title>Java Practical</title>
    <script src="index.js"></script>
    <!-- Syntax highlighting for code display -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.10.0/styles/vs2015.min.css">
    <script src="/path/to/highlight.min.js"></script>
</head>

<body>
    <!-- Navigation bar -->
    <nav>
        <h1>Java Programming Language</h1>
        <a href="index.php">Home</a>
    </nav>

    <?php
        /**
         * Main routing logic:
         * - If 'dir' parameter is set, display programs from that directory
         * - Otherwise, display all available directories as containers
         */
        if (isset($_GET["dir"])){
            $dir = $_GET["dir"];
            // Security: Use basename to prevent directory traversal attacks
            $dir = basename($dir);
            
            if (is_dir($dir)){
                indexCodes($dir);
            }
        } 
        else{
            // Display directory containers on homepage
            echo '<div class="containers">';
            indexContainer();
            echo '</div>';
        }

        /**
         * Compiles and executes a Java program, returning the output
         * 
         * @return string HTML formatted output in terminal style
         */
        function showOutput(){
            if (isset($_POST["code"])){
                $path = $_POST["code"];
                
                // Compile the Java file
                $compile = shell_exec("javac $path 2>&1");
                
                // Only execute if no validation parameter is set
                if (!(isset($_GET['val']))){
                    $stack = [];
                    $tokens = [];
                    
                    // Read the Java file
                    $text = file($path);
                    
                    if (count($text) > 0){
                        // Tokenize the Java code to find class names
                        foreach ($text as $line) {
                            // Remove spaces between identifiers and brackets
                            $line = preg_replace('/(\w+)\s+([\(\{\[])/','$1$2',$line);
                            $split = preg_split("/\s+/",$line,-1,PREG_SPLIT_NO_EMPTY);  
                            
                            if (count($split) != 0){
                                $tokens = array_merge($tokens,$split);
                            }
                        }
                    }
                    
                    // Parse tokens to find the main class
                    $stack = [];
                    foreach ($tokens as $tkn => $val){
                        // Track class declarations
                        if ((strtolower($val) == "class") && ($tkn != count($tokens) - 1)){
                            $stack[] = $tokens[$tkn + 1];
                        }
                        // Pop stack on closing brackets
                        elseif (preg_match("/[\)\}\]]/",$val) != 0) {
                            array_pop($stack);
                        }
                        // Stop when main method is found
                        elseif (preg_match("/main/",$val) != 0) {
                            break;
                        }
                    }
                    
                    // Execute the Java program if class was found
                    if (count($stack) > 0){
                        $class = $stack[count($stack) - 1];
                        // Remove trailing bracket if present
                        $class = substr($class, 0, strlen($class) - 1);
                        
                        // Change to the directory containing the Java file
                        $classPath = substr($path, 0, strrpos($path, "/"));
                        echo "<script>console.log('$classPath')</script>";
                        chdir($classPath);
                        
                        // Execute the Java program
                        $output = shell_exec("java $class 2>&1");
                        
                        // Return to parent directory
                        chdir("..");
                        
                        // Return formatted output
                        return "<div class='terminal'><label class='prompt'>Output</label><pre class='output'><code>$output</code></pre></div>";
                    }
                }  
            }
        }
        
        /**
         * Scans current directory and displays all subdirectories as clickable containers
         * Each container represents a category of Java programs
         */
        function indexContainer(){
            $items = scandir(".");
            
            foreach ($items as $item){
                // Format directory name for display
                $name = strtoupper(str_replace("_", " ", trim($item)));
                
                // Only display valid directories (exclude . and ..)
                if ($item != "." && $item != ".." && $name != "" && is_dir($item)){
                    $comm = "<a href='?dir=$item' class='container'> <div>$name</div></a>";
                    echo $comm;
                    echo "<script>console.log(\"$comm\");</script>";
                }
            }
        }

        /**
         * Displays all Java programs in a given directory with:
         * - Table of contents with program numbers and names
         * - Individual program code displays with syntax highlighting
         * - Run button for each program
         * 
         * @param string $dir Directory name to scan for Java files
         */
        function indexCodes($dir){
            // Start building table of contents
            $table_str = <<<HTM
            <table>
                <tr>
                    <th>SERIAL NUMBER</th>
                    <th>NAME OF PROGRAM</th>
                </tr>
HTM;
            
            $program_strs = []; // Array to store program HTML
            $items = scandir($dir);
            
            // Custom sort function for natural numeric ordering (p1, p2... p10)
            usort($items, function($a, $b) {
                return strnatcmp($a, $b);
            });
            
            foreach ($items as $item){
                $num = strtoupper(str_replace("_", " ", trim($item))); 
                
                // Only process Java files
                if ($item != "." && $item != ".." && $num != "" && !(is_dir($item)) && strrpos($num, "JAVA")){
                    $path = "$dir/$item";
                    $text = file($path);
                    
                    if (count($text) > 0){
                        // Extract program name and number from first line
                        preg_match("/[A-Za-z].*/",$text[0],$line);
                        preg_match("/\d.*?\.\s/",$text[0],$num_match);
                        
                        // Check if matches were found before accessing array
                        if (isset($num_match[0]) && isset($line[0])){
                            $num = substr($num_match[0], 0, strlen($num_match[0]) - 2);
                            $line = $line[0];
                        } else {
                            // Fallback: use filename as program identifier
                            $num = str_replace('.java', '', $item);
                            $line = "Program from " . $item;
                        }
                        
                        // Prepare code for display
                        $text_str = implode("\n ", $text);
                        
                        // Add row to table of contents
                        $table_str .= <<<HTM
                            <tr>
                                <td>$num</td>
                                <td><a href="#prg$num">$line</a></td>
                            </tr>
HTM;       
                        
                        // Escape HTML special characters in code
                        $text_str = htmlspecialchars($text_str); 
                        
                        // Check if this program was just executed
                        if (isset($_POST["code"]) && $_POST["code"] == $path){
                            $output = showOutput();
                            
                            // Display with output
                            $program_strs[] = <<<HTM
                                <div class="programsTop">
                                    <label for="code$num">Program $num</label>
                                    <button type="submit" name="code" value="$path">Run Code</button>
                                </div>
                                <div class="prgrm" id="prg$num">
                                    <pre><code id="code$num">$text_str</code></pre>
                                </div>
                                $output
HTM;
                        }       
                        else{
                            // Display without output
                            $program_strs[] = <<<HTM
                                <div class="programsTop">
                                    <label for="code$num">Program $num</label>
                                    <button type="submit" name="code" value="$path">Run Code</button>
                                </div>
                                <div class="prgrm" id="prg$num">
                                    <pre><code id="code$num">$text_str</code></pre>
                                </div>
HTM;
                        }      
                    }
                }
            }
            
            // Close table and display all programs
            $table_str .= "</table>";
            echo $table_str;
            
            // Wrap programs in a form for submission
            echo '<div id="programsContainer"><form method="post">';
            foreach ($program_strs as $key => $program_str) {
                echo $program_str;
            }
            echo '</form></div>';
        } 
    ?>

    <!-- Syntax highlighting library -->
    <script src="https://cdnjs.cloudflare.com/ajax/libs/highlight.js/11.9.0/highlight.min.js"></script>
    <script>hljs.highlightAll();</script>
</body>

</html>