/*
17. Queue based approach for first non-repeating character in a stream

Explanation -

Given a stream of characters and we have to find first non repeating character each time a character is inserted to the stream. Examples: Input : a a b c Output : a -1 b b Input : a a c Output : a -1 c
*/
#include <iostream>
#include <climits>

void firstNonRepeatingCharacter(char stream[], int n) {
    int freq[256] = {0};           // Array to store frequency of characters (ASCII size)
    int index[256];                // Array to store the first occurrence index of characters
    for (int i = 0; i < 256; i++) {
        index[i] = INT_MAX;        // Initialize all entries to maximum value
    }

    for (int i = 0; i < n; i++) {
        char ch = stream[i];
        freq[ch]++;                // Increment frequency of current character

        // Update the first occurrence index if character appears for the first time
        if (freq[ch] == 1) {
            index[ch] = i;
        }

        // Find the first non-repeating character by checking the smallest index in index array
        int minIndex = INT_MAX;
        char firstNonRepeating = -1;
        for (int j = 0; j < 256; j++) {
            if (freq[j] == 1 && index[j] < minIndex) {
                minIndex = index[j];
                firstNonRepeating = j;
            }
        }

        // Output the first non-repeating character or -1 if there isn't one
        if (firstNonRepeating == -1) {
            std::cout << "-1 ";
        } else {
            std::cout << firstNonRepeating << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of characters in the stream: ";
    std::cin >> n;

    char stream[n];
    std::cout << "Enter the stream of characters: ";
    for (int i = 0; i < n; i++) {
        std::cin >> stream[i];
    }

    std::cout << "First non-repeating character at each step: ";
    firstNonRepeatingCharacter(stream, n);

    return 0;
}
