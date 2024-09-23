// 1. IMPLEMENT THE OPERATIONS OF SIMPLE QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)
#include <stdio.h>
#define size 100
void insert() {}
void delete() {}
void peek() {}
void isEmpty() {}
void isFull(){}
int main()
{
    int queue[size];
    int value,int front;
    int choice = 4;
    while (1)
    {
        printf("\n1.INSERT\n2.DELETE\n3.PEEK\n4.ISEMPTY\n5.ISFULL\n6.EXIT\nENTER THE OPERATION: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER THE VALUE: ");
            scanf("%d", &value);
            insert(queue, front, rear, value);
            break;
        case 2:
            delete (queue);
            break;
        case 3:
            peek(queue);
            break;
        case 4:
            isEmpty(queue);
            break;
        case 5:
            isFull(queue);
            break;
        case 6:
            return 0;
        default:
            break;
        }
    }
}