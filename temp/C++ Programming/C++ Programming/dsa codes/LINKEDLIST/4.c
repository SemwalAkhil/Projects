#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

int isEmpty() {
    return head == NULL;
}

void insertAtBegin(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (isEmpty()) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    if (isEmpty()) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Node* last = head->prev;
        newNode->next = head;
        newNode->prev = last;
        last->next = newNode;
        head->prev = newNode;
    }
}

void deleteAtBegin() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        Node* last = head->prev;
        head = head->next;
        last->next = head;
        head->prev = last;
        free(temp);
    }
}

void deleteAtEnd() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    Node* last = head->prev;
    if (last == head) {
        free(head);
        head = NULL;
    } else {
        last->prev->next = head;
        head->prev = last->prev;
        free(last);
    }
}

void display() {
    if (isEmpty()) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete at Beginning\n4. Delete at End\n5. Display\n6. Exit\nChoose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBegin(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
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
