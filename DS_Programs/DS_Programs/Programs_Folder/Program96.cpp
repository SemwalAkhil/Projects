// 18. ENTER THE STRING FROM THE USER AND CONVERT INTO AN INTEGER VALUE?
#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);  // Take input string from the user

    std::cout << "ASCII values of the characters in the string are:\n";
    for (char ch : input) {
        std::cout << "'" << ch << "' : " << static_cast<int>(ch) << std::endl;
    }

    return 0;
}

