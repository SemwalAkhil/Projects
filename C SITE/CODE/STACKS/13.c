// 13. IMPLEMENT THE TOWER OF HANOI USING STACKS.
/*
    The Tower of Hanoi (also called The problem of Benares Temple or Tower of Brahma or Lucas' Tower and sometimes pluralized as Towers, or simply pyramid puzzle) is a mathematical game or puzzle consisting of three rods and a number of disks of various diameters, which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape. The objective of the puzzle is to move the entire stack to one of the other rods, obeying the following rules:
        Only one disk may be moved at a time.
        Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
        No disk may be placed on top of a disk that is smaller than it.
*/
#include <stdio.h>
#define MAX_DISCS 5
#define MIN_DISCS 3
#define MID_DISCS 4

void push(int *stack, int *top, int val)
{
    stack[++(*top)] = val;
}

int pop(int *stack, int *top)
{
    return stack[(*top)--];
}

int peek(int *stack, int *top)
{
    return stack[*top];
}

static inline int isEmpty(int *stack, int *top)
{
    return *top == -1;
}

static inline int isFull(int *stack, int *top, int level)
{
    return *top == (level - 1);
}

void displayRods(int rodArray[3][MAX_DISCS], int topArray[3])
{
    for (int j = 0; j < 3; j++)
    {
        printf("Rod %d: ", j + 1);
        for (int k = topArray[j]; k >= 0; k--)
        {
            printf("%d ", rodArray[j][k]);
        }
        printf("\n");
    }
    printf("------------------------------------\n");
}

int main()
{
    int level;
    int rodArray[3][MAX_DISCS] = {0};
    int topArray[3] = {-1, -1, -1}; // Top indices of each rod
    int discs;
    int from, to;

    printf("1. EASY\n2. MEDIUM\n3. HARD\nCHOOSE LEVEL: ");
    scanf("%d", &level);
    printf("MOVE FROM ROD 1 TO ROD 3\n");
    // Set number of discs based on difficulty level
    if (level == 1)
    {
        discs = MIN_DISCS;
    }
    else if (level == 2)
    {
        discs = MID_DISCS;
    }
    else if (level == 3)
    {
        discs = MAX_DISCS;
    }
    else
    {
        discs = MIN_DISCS;
    }

    // Initialize the first rod with discs
    for (int i = discs; i > 0; i--)
    {
        push(rodArray[0], &topArray[0], i); // Push discs onto the first rod
    }

    // Display initial state
    displayRods(rodArray, topArray);

    while (1)
    {
        printf("MOVE FROM (1/2/3): ");
        scanf("%d", &from);
        printf("MOVE TO (1/2/3): ");
        scanf("%d", &to);

        // Validate the move
        if (isEmpty(rodArray[from - 1], &topArray[from - 1]) ||
            (!isEmpty(rodArray[to - 1], &topArray[to - 1]) &&
             rodArray[from - 1][topArray[from - 1]] > rodArray[to - 1][topArray[to - 1]]))
        {
            printf("MOVE FAILED: Invalid move!\n");
        }
        else
        {
            // Perform the move
            push(rodArray[to - 1], &topArray[to - 1], pop(rodArray[from - 1], &topArray[from - 1]));
            displayRods(rodArray, topArray); // Display state after the move
        }

        // Check if the game is won (all discs on the last rod)
        if (topArray[2] == discs - 1)
        {
            printf("Congratulations! You solved the Tower of Hanoi!\n");
            break;
        }
    }

    return 0;
}
