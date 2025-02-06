// 13. IMPLEMENT THE TOWER OF HANOI USING STACKS.
/*
    The Tower of Hanoi (also called The problem of Benares Temple or Tower of Brahma or Lucas' Tower and sometimes pluralized as Towers, or simply pyramid puzzle) is a mathematical game or puzzle consisting of three rods and a number of disks of various diameters, which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape. The objective of the puzzle is to move the entire stack to one of the other rods, obeying the following rules:
        Only one disk may be moved at a time.
        Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
        No disk may be placed on top of a disk that is smaller than it.
*/
#include <stdio.h>
#define max 5
#define mid 4
#define min 3
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
int main()
{
    int level;
    int rodArray[3][max];
    int topArray[] = {-1, -1, -1};
    int discs;
    int from;
    int to;
    printf("1.EASY\n2.MEDIUM\n3.HARD\nCHOOSE LEVEL: ");
    scanf("%d", &level);
    if (level == 1)
    {
        level = min;
    }
    else if (level == 2)
    {
        level = mid;
    }
    else if (level == 3)
    {
        level = max;
    }
    else
    {
        level = min;
    }
    for (int i = level; i > 0; i--)
    {
        push(rodArray[0], &topArray[0], i);
    }

    while (1)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = topArray[j]; k >= 0; k--)
            {
                for (int i = 0; i < rodArray[j][k]; i++)
                {
                    printf("*");
                }
                printf("\n");
            }
            printf("------------------------------------\n");
        }
        printf("MOVE FROM (1/2/3) : ");
        scanf("%d", &from);
        printf("MOVE TO (1/2/3) : ");
        scanf("%d", &to);
        if (isEmpty(rodArray[from - 1], &topArray[from - 1]) || ((rodArray[from - 1][topArray[from - 1]] > rodArray[to - 1][topArray[to - 1]]) && (topArray[to - 1] != -1)))
        {
            printf("MOVE FAILED\n");
        }
        else
        {
            push(rodArray[to - 1], &topArray[to - 1],
                 pop(rodArray[from - 1], &topArray[from - 1]));
        }
    }
}
