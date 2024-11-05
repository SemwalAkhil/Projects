// 21. PRINT ALL THE PERMUTATION OF A STRING I.E. "ABCDE".
#include <stdio.h>

int getStrLen(char str[])
{
    int i;
    for (i = 0; str[i] != 0; i++)
        continue;
    return i;
}

// Function to swap characters at positions i and j in the array
void swap(char *str, int i, int j)
{
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

// Recursive function to generate permutations
void generatePermutations(char *str, int start, int end)
{
    // Base case: if we've reached the end of the string
    if (start == end)
    {
        printf("%s\n", str);
        return;
    }

    // Try all possible characters for current position
    for (int i = start; i <= end; i++)
    {
        // Swap current character with character at position 'start'
        swap(str, start, i);

        // Recursively generate permutations for remaining characters
        generatePermutations(str, start + 1, end);

        // Backtrack: restore the string to its previous state
        swap(str, start, i);
    }
}

int main()
{
    char str[100]; // Array to store input string

    // Get string input from user
    printf("Enter a string to generate all permutations: ");
    scanf("%s", str);

    int n = getStrLen(str); // Get length of input string

    // Calculate total number of permutations
    int total = 1;
    for (int i = 1; i <= n; i++)
    {
        total *= i;
    }

    printf("\nAll possible permutations (%d total):\n", total);
    generatePermutations(str, 0, n - 1);

    return 0;
}