// IMPLEMENT THE OPERATIONS OF DOUBLY CIRCULAR LINKED LIST STORING INTEGER VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    Node* tail;

public:
    DoublyCircularLinkedList() {
        tail = nullptr;
    }

    // Check if the list is empty
    bool isEmpty() {
        return tail == nullptr;
    }

    // Display all elements in the list
    void display() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = tail->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != tail->next);
        cout << endl;
    }

    // Insert at the beginning
    void insertAtBegin(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
        } else {
            newNode->next = tail->next;
            newNode->prev = tail;
            tail->next->prev = newNode;
            tail->next = newNode;
        }
    }

    // Insert at a specific position
    void insertAtPos(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (pos == 1) {
            insertAtBegin(value);
            return;
        }

        Node* current = tail->next;
        for (int i = 1; i < pos - 1 && current != tail; i++) {
            current = current->next;
        }

        if (current == tail && pos > 2) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;

        if (current == tail) {
            tail = newNode;
        }
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            tail = newNode;
            tail->next = tail;
            tail->prev = tail;
        } else {
            newNode->next = tail->next;
            newNode->prev = tail;
            tail->next->prev = newNode;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete at the beginning
    void deleteAtBegin() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node* temp = tail->next;
        if (tail->next == tail) {  // Only one node
            delete temp;
            tail = nullptr;
        } else {
            tail->next = temp->next;
            temp->next->prev = tail;
            delete temp;
        }
    }

    // Delete at the end
    void deleteAtEnd() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node* temp = tail;
        if (tail->next == tail) {  // Only one node
            delete tail;
            tail = nullptr;
        } else {
            tail->prev->next = tail->next;
            tail->next->prev = tail->prev;
            tail = tail->prev;
            delete temp;
        }
    }

    // Delete at a specific position
    void deleteAtPos(int pos) {
        if (isEmpty() || pos < 1) {
            cout << "List is empty or invalid position." << endl;
            return;
        }

        if (pos == 1) {
            deleteAtBegin();
            return;
        }

        Node* current = tail->next;
        for (int i = 1; i < pos && current != tail; i++) {
            current = current->next;
        }

        if (current == tail && pos > 2) {
            cout << "Position out of range!" << endl;
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (current == tail) {
            tail = current->prev;
        }
        delete current;
    }

    // Search for an element
    bool search(int value) {
        if (isEmpty()) {
            return false;
        }

        Node* current = tail->next;
        do {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        } while (current != tail->next);

        return false;
    }

    // Check if the list is full
    // (Since we're using dynamic memory allocation, we assume it's not full unless memory allocation fails)
    bool isFull() {
        Node* testNode = new(nothrow) Node(0);
        if (!testNode) {
            return true;
        }
        delete testNode;
        return false;
    }
};

int main() {
    DoublyCircularLinkedList list;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Begin\n";
        cout << "2. Insert at Position\n";
        cout << "3. Insert at End\n";
        cout << "4. Delete at Begin\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display List\n";
        cout << "8. Search Element\n";
        cout << "9. Check if Empty\n";
        cout << "10. Check if Full\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                list.insertAtBegin(value);
                break;

            case 2:
                cout << "Enter value to insert and position: ";
                cin >> value >> pos;
                list.insertAtPos(value, pos);
                break;

            case 3:
                cout << "Enter value to insert at end: ";
                cin >> value;
                list.insertAtEnd(value);
                break;

            case 4:
                list.deleteAtBegin();
                break;

            case 5:
                list.deleteAtEnd();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deleteAtPos(pos);
                break;

            case 7:
                list.display();
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                if (list.search(value)) {
                    cout << "Element found in the list." << endl;
                } else {
                    cout << "Element not found in the list." << endl;
                }
                break;

            case 9:
                if (list.isEmpty()) {
                    cout << "List is empty." << endl;
                } else {
                    cout << "List is not empty." << endl;
                }
                break;

            case 10:
                if (list.isFull()) {
                    cout << "List is full." << endl;
                } else {
                    cout << "List is not full." << endl;
                }
                break;

            case 11:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 11);

    return 0;
}
