#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
} Node;

Node* head = NULL;

int isEmpty() {
    return head == NULL;
}

void insertAtBegin(char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (isEmpty()) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtBegin() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void display() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    while (temp) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    char value[100];

    while (1) {
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete at Beginning\n4. Delete at End\n5. Display\n6. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character
        switch (choice) {
            case 1:
                printf("Enter string to insert: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0;  // Remove newline character
                insertAtBegin(value);
                break;
            case 2:
                printf("Enter string to insert: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0;
                insertAtEnd(value);
                break;
            case 3:
                deleteAtBegin();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}
