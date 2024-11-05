// 27. DISPLAY THE STRING ON THE OUTPUT SCREEN BUT ASK THE TEXT ALIGNMENT OPTION GIVEN BY THE USER (1 FOR LEFT, 2 FOR CENTER, 3 RIGHT)
#include <stdio.h>

int getStrLen(char str[])
{
    int i;
    for (i = 0; str[i] != 0; i++)
        continue;
    return i;
}
// Function to print spaces
void printSpaces(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf(" ");
    }
}

// Function to print text with specified alignment
void printAlignedText(char *text, int width, int alignment)
{
    int len = getStrLen(text);
    int spaces;

    switch (alignment)
    {
    case 1: // Left alignment
        printf("%s\n", text);
        break;

    case 2: // Center alignment
        spaces = (width - len) / 2;
        printSpaces(spaces);
        printf("%s\n", text);
        break;

    case 3: // Right alignment
        spaces = width - len;
        printSpaces(spaces);
        printf("%s\n", text);
        break;

    default:
        printf("Invalid alignment option!\n");
    }
}

int main()
{
    char text[1000];
    int choice;
    const int SCREEN_WIDTH = 80; // Assuming standard terminal width

    // Get the text from user
    printf("Enter the text: ");
    gets(text); // Using gets() for demonstration. In production code, fgets() is safer

    // Display menu
    printf("\nChoose text alignment:\n");
    printf("1. Left Alignment\n");
    printf("2. Center Alignment\n");
    printf("3. Right Alignment\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    printf("\nFormatted output:\n");
    printf("----------------\n");

    // Print the text with chosen alignment
    printAlignedText(text, SCREEN_WIDTH, choice);

    return 0;
}