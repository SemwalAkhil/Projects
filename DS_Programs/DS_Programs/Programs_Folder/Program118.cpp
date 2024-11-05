//  IMPLEMENT THE OPERATIONS OF SINGLE LINKED LIST STORING STRING VALUES (INSERT AT BEGIN,INSERT AT POS,INSERT AT END,DELETE AT BEGIN,DELETE AT END, DELETE AT POS, ISEMPTY, ISFULL, DISPLAY, SEARCH)

#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    // Check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Display all elements in the list
    void display() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Insert at the beginning
    void insertAtBegin(string value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at a specific position
    void insertAtPos(string value, int pos) {
        if (pos < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (pos == 1) {
            insertAtBegin(value);
            return;
        }

        Node* current = head;
        for (int i = 1; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Position out of range!" << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Insert at the end
    void insertAtEnd(string value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete at the beginning
    void deleteAtBegin() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at the end
    void deleteAtEnd() {
        if (isEmpty()) {
            cout << "List is empty, cannot delete." << endl;
            return;
        }

        if (head->next == nullptr) { // Only one node
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
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

        Node* current = head;
        for (int i = 1; i < pos - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    // Search for an element
    bool search(string value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Check if the list is full
    // (Since we're using dynamic memory allocation, we assume it's not full unless memory allocation fails)
    bool isFull() {
        Node* testNode = new(nothrow) Node("");
        if (!testNode) {
            return true;
        }
        delete testNode;
        return false;
    }
};

int main() {
    SinglyLinkedList list;
    int choice, pos;
    string value;

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
