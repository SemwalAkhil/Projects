#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[100];
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

int isEmpty() {
    return head == NULL;
}

void insertAtBegin(char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);

    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, value);

    if (isEmpty()) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* tail = head->prev;
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
}

void deleteAtBegin() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        Node* tail = head->prev;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        free(head->prev);
    }
}

void deleteAtEnd() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        Node* tail = head->prev;
        tail->prev->next = head;
        head->prev = tail->prev;
        free(tail);
    }
}

void display() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%s <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice;
    char value[100];

    while (1) {
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete at Beginning\n4. Delete at End\n5. Display\n6. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Enter string to insert: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = 0;
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
