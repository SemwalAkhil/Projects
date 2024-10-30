// 28. CREATE A DICTIONARY HAVING 10 WORDS AND THEIR MEANING WITH FOLLOWING OPERATIONS. [CREATE, DELETE, SEARCH].
#include <stdio.h>
#include <conio.h>
#define maxSize 100
int create(char dict[10][maxSize], char row[maxSize])
{
    for (int i = 0; i < 10; i++)
    {
        if (dict[i][0] == 0)
        {
            for (int j = 0; row[j] != 0; j++)
            {
                dict[i][j] = row[j];
            }
            return 1;
        }
    }
    return 0;
}
int delete(char dict[10][maxSize], int index)
{
    if ((index < 10) && (index >= 0))
    {
        dict[index][0] = 0;
        return 1;
    }
    return 0;
}
int search(char dict[10][maxSize], char term[maxSize])
{
    int j;
    int match = 0;
    for (int i = 0; i < 10; i++)
    {
        for (j = 0; (dict[i][j] != '-') && (dict[i][j] != 0); j++)
        {
            if (term[j] != dict[i][j])
            {
                match = 0;
                break;
            }
            else
            {
                match = 1;
            }
        }
        if (match)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    char dict[10][maxSize] = {0};
    int choice;
    int i;
    int pos;
    char term[maxSize];
    while (1)
    {
        printf("1. Create Term\n2.Delete Term\n3.Search Term\n4.Exit\nEnter Operation : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter term :");
            fflush(stdin);
            for (i = 0; i < maxSize; i++)
            {
                term[i] = getchar();
                if (term[i] == '\n')
                {
                    term[i] = '-';
                    i++;
                    break;
                }
            }
            if (i >= maxSize)
            {
                printf("Insertion Failed. Oversized Term\n");
                break;
            }
            fflush(stdin);
            printf("Enter definition :");
            for (; i < maxSize; i++)
            {
                term[i] = getchar();
                if (term[i] == '\n')
                {
                    term[i] = 0;
                    break;
                }
            }
            if (i >= maxSize)
            {
                printf("Insertion Failed. Size overflow\n");
                break;
            }
            (create(dict, term) == 1) ? printf("Inserted %s\n", term) : printf("Insertion Failed Dictionary Full\n");
            break;
        case 2:
            printf("Enter term to delete : ");
            fflush(stdin);
            gets(term);
            pos = search(dict, term);
            if (pos == -1)
            {
                printf("Value does not exist\n");
            }
            else
            {
                delete (dict, pos) ? printf("Value deleted\n") : printf("Deletion Failed\n");
            }
            break;
        case 3:
            printf("Enter term to search : ");
            fflush(stdin);
            gets(term);
            pos = search(dict, term);
            (pos == -1) ? printf("Value not found\n") : printf("%s\n", dict[pos]);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice try again\n");
            break;
        }
    }
}