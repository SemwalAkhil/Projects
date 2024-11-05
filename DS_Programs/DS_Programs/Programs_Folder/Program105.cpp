#include <iostream>
#include <string>
#include <iomanip>

void displayAlignedText(const std::string &text, int alignment, int width = 50) {
    switch (alignment) {
        case 1:  // Left alignment
            std::cout << text << std::endl;
            break;
        case 2:  // Center alignment
            std::cout << std::setw((width + text.length()) / 2) << text << std::endl;
            break;
        case 3:  // Right alignment
            std::cout << std::setw(width) << text << std::endl;
            break;
        default:
            std::cout << "Invalid alignment option." << std::endl;
    }
}

int main() {
    std::string text;
    int alignment;

    // Input string
    std::cout << "Enter a string: ";
    std::getline(std::cin, text);

    // Choose alignment option
    std::cout << "Choose alignment option (1 for Left, 2 for Center, 3 for Right): ";
    std::cin >> alignment;

    // Display text based on chosen alignment
    std::cout << "\nAligned Text:\n";
    displayAlignedText(text, alignment);

    return 0;
}
