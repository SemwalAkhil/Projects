#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top1;
    int top2;
} TwoStacks;

void initialize(TwoStacks *stacks) {
    stacks->top1 = -1; // Stack 1
    stacks->top2 = MAX; // Stack 2
}

void push1(TwoStacks *stacks, int value) {
    if (stacks->top1 + 1 == stacks->top2) {
        printf("Stack 1 Overflow\n");
        return;
    }
    stacks->arr[++stacks->top1] = value;
}

void push2(TwoStacks *stacks, int value) {
    if (stacks->top2 - 1 == stacks->top1) {
        printf("Stack 2 Overflow\n");
        return;
    }
    stacks->arr[--stacks->top2] = value;
}

int pop1(TwoStacks *stacks) {
    if (stacks->top1 == -1) {
        printf("Stack 1 Underflow\n");
        return -1; // Indicate an error
    }
    return stacks->arr[stacks->top1--];
}

int pop2(TwoStacks *stacks) {
    if (stacks->top2 == MAX) {
        printf("Stack 2 Underflow\n");
        return -1; // Indicate an error
    }
    return stacks->arr[stacks->top2++];
}

void displayStacks(TwoStacks *stacks) {
    printf("Stack 1: ");
    for (int i = 0; i <= stacks->top1; i++) {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");

    printf("Stack 2: ");
    for (int i = MAX - 1; i >= stacks->top2; i--) {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");
}

int main() {
    TwoStacks stacks;
    initialize(&stacks);
    int choice, value;

    while (1) {
        printf("\n1. Push to Stack 1\n2. Push to Stack 2\n3. Pop from Stack 1\n4. Pop from Stack 2\n5. Display Stacks\n6. Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push into Stack 1: ");
                scanf("%d", &value);
                push1(&stacks, value);
                break;
            case 2:
                printf("Enter value to push into Stack 2: ");
                scanf("%d", &value);
                push2(&stacks, value);
                break;
            case 3:
                value = pop1(&stacks);
                if (value != -1) {
                    printf("Popped from Stack 1: %d\n", value);
                }
                break;
            case 4:
                value = pop2(&stacks);
                if (value != -1) {
                    printf("Popped from Stack 2: %d\n", value);
                }
                break;
            case 5:
                displayStacks(&stacks);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
