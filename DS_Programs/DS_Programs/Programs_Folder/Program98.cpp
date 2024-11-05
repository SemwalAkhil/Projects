// 20. ENTER THE STRING FROM THE USER AND COUNT THE NUMBER OF CHARACTERS, WORDS, SPACES AND LINES
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::string line;
    int charCount = 0, wordCount = 0, spaceCount = 0, lineCount = 0;

    std::cout << "Enter text (press Ctrl+D or Ctrl+Z to end input):\n";

    // Reading multiple lines of input
    while (std::getline(std::cin, line)) {
        input += line + '\n';  // Append each line to input with a newline
        lineCount++;
    }

    bool inWord = false;
    for (char ch : input) {
        charCount++;  // Count each character
        if (ch == ' ') {
            spaceCount++;  // Count spaces
            inWord = false;  // End of a word
        } else if (ch == '\n') {
            inWord = false;  // End of a word
        } else {
            if (!inWord) {
                wordCount++;  // New word found
                inWord = true;
            }
        }
    }

    // Display the results
    std::cout << "Number of characters: " << charCount << std::endl;
    std::cout << "Number of words: " << wordCount << std::endl;
    std::cout << "Number of spaces: " << spaceCount << std::endl;
    std::cout << "Number of lines: " << lineCount << std::endl;

    return 0;
}
