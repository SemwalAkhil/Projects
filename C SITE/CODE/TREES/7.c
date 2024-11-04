// 7. CREATE BINARY SEARCH TREE USING ARRAYS (INSERT, DELETE, SEARCH, PREORDER, INORDER, POSTORDER, MINIMUM ELEMENT)
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define maximum size of the BST

// Structure to represent the BST
struct BST
{
    int data[MAX_SIZE];
    int size;
};

// Function to create an empty BST
struct BST *createBST()
{
    struct BST *bst = (struct BST *)malloc(sizeof(struct BST));
    bst->size = 0; // Initialize size to 0
    return bst;
}

// Function to search for a value in the BST
int search(struct BST *bst, int value)
{
    for (int i = 0; i < bst->size; i++)
    {
        if (bst->data[i] == value)
        {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Function to insert a value into the BST without allowing duplicates
void insert(struct BST *bst, int value)
{
    // Check if the value already exists in the BST
    if (search(bst, value) != -1)
    {
        printf("Value %d already exists in the BST.\n", value);
        return;
    }

    if (bst->size == MAX_SIZE)
    {
        printf("BST is full, cannot insert %d\n", value);
        return;
    }

    // Insert the new value
    bst->data[bst->size] = value;
    bst->size++;

    // Bubble up the newly added value to maintain BST properties
    for (int i = bst->size - 1; i > 0; i--)
    {
        if (bst->data[i] < bst->data[(i - 1) / 2])
        {
            // Swap with parent
            int temp = bst->data[i];
            bst->data[i] = bst->data[(i - 1) / 2];
            bst->data[(i - 1) / 2] = temp;
        }
        else
        {
            break;
        }
    }
}

// Function to find the minimum element in the BST
int minimum(struct BST *bst)
{
    if (bst->size == 0)
    {
        printf("BST is empty.\n");
        return -1; // Return -1 if BST is empty
    }
    int min = bst->data[0];
    for (int i = 1; i < bst->size; i++)
    {
        if (bst->data[i] < min)
        {
            min = bst->data[i];
        }
    }
    return min;
}

// Function to perform inorder traversal
void inorder(struct BST *bst, int index)
{
    if (index >= bst->size)
        return;
    inorder(bst, 2 * index + 1);     // Visit left child
    printf("%d ", bst->data[index]); // Visit node
    inorder(bst, 2 * index + 2);     // Visit right child
}

// Function to perform preorder traversal
void preorder(struct BST *bst, int index)
{
    if (index >= bst->size)
        return;
    printf("%d ", bst->data[index]); // Visit node
    preorder(bst, 2 * index + 1);    // Visit left child
    preorder(bst, 2 * index + 2);    // Visit right child
}

// Function to perform postorder traversal
void postorder(struct BST *bst, int index)
{
    if (index >= bst->size)
        return;
    postorder(bst, 2 * index + 1);   // Visit left child
    postorder(bst, 2 * index + 2);   // Visit right child
    printf("%d ", bst->data[index]); // Visit node
}

// Function to delete a value from the BST
void delete(struct BST *bst, int value)
{
    int index = search(bst, value);
    if (index == -1)
    {
        printf("Value %d not found in BST.\n", value);
        return;
    }

    // Move the last element to the place of the deleted element
    bst->data[index] = bst->data[bst->size - 1];
    bst->size--; // Reduce size
}

// Menu-driven program to interact with the user
int main()
{
    struct BST *bst = createBST();
    int choice, value;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Find Minimum Element\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(bst, value);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            delete (bst, value);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            int searchResult = search(bst, value);
            if (searchResult != -1)
            {
                printf("Value %d found at index %d.\n", value, searchResult);
            }
            else
            {
                printf("Value %d not found in BST.\n", value);
            }
            break;
        case 4:
            printf("Preorder Traversal: ");
            preorder(bst, 0);
            printf("\n");
            break;
        case 5:
            printf("Inorder Traversal: ");
            inorder(bst, 0);
            printf("\n");
            break;
        case 6:
            printf("Postorder Traversal: ");
            postorder(bst, 0);
            printf("\n");
            break;
        case 7:
            value = minimum(bst);
            if (value != -1)
            {
                printf("Minimum element: %d\n", value);
            }
            break;
        case 8:
            printf("Exiting...\n");
            free(bst);
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
