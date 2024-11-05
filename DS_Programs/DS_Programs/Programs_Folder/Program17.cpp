// ENTER A STRING FROM THE USER, ENTER A CHARACTER AND PERFORM LINEAR SEARCH ALGORITHM THROUGH RECURSION

#include <stdio.h>

int linearSearch(char str[], char target, int index) {
    if (str[index] == '\0') 
        return -1;

    if (str[index] == target)
        return index;

    return linearSearch(str, target, index + 1);
}

int main() {
    char str[100], target;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the character to search for: ");
    scanf("%c", &target);

    // Perform recursive linear search
    int result = linearSearch(str, target, 0);

    // Output the result
    if (result != -1) {
        printf("Character '%c' found at index %d\n", target, result);
    } else {
        printf("Character '%c' not found in the string\n", target);
    }

    return 0;
}
