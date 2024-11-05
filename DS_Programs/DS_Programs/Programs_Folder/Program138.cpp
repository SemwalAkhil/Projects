/*Length of the longest valid substring

Explanation -

Given a string consisting of opening and closing parenthesis, find the length of the longest valid parenthesis substring. Examples: Input : ((() Output : 2 Explanation : () Input: )()()) Output : 4 Explanation: ()() Input: ()(())))) Output: 6 Explanation: ()(())*/

#include <iostream>

int longestValidParentheses(const char* s) {
    int leftToRightCount = 0, rightToLeftCount = 0;  // Counters for parentheses
    int maxLength = 0;
    int length = 0;

    // Left-to-right scan
    while (s[length] != '\0') length++;  // Get the length of the input C-style string

    int left = 0, right = 0;
    for (int i = 0; i < length; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            maxLength = std::max(maxLength, 2 * right);  // Valid substring of equal '(' and ')'
        } else if (right > left) {
            left = right = 0;  // Reset counters if unbalanced
        }
    }

    // Right-to-left scan
    left = right = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            maxLength = std::max(maxLength, 2 * left);  // Valid substring of equal '(' and ')'
        } else if (left > right) {
            left = right = 0;  // Reset counters if unbalanced
        }
    }

    return maxLength;
}

int main() {
    char s[100];
    std::cout << "Enter a string of parentheses: ";
    std::cin >> s;

    int result = longestValidParentheses(s);
    std::cout << "Length of the longest valid substring: " << result << std::endl;

    return 0;
}
