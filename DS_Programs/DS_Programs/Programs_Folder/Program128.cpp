// IMPLEMENT THE OPERATIONS OF QUEUE DYNAMICALLY OF STRING (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)

#include <iostream>
#include <string>

class Node {
public:
    std::string data;
    Node* next;
    Node(const std::string& value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;  // Pointer to the front element
    Node* rear;   // Pointer to the rear element

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to insert a string into the queue
    void insert(const std::string& value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {  // If queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << "Inserted \"" << value << "\" into the queue.\n";
    }

    // Function to delete a string from the queue
    void deleteElement() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot delete.\n";
            return;
        }
        Node* temp = front;
        std::cout << "Deleted \"" << front->data << "\" from the queue.\n";
        front = front->next;
        delete temp;
        if (front == nullptr) {  // If the queue becomes empty
            rear = nullptr;
        }
    }

    // Function to get the front element of the queue
    std::string peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Nothing to peek.\n";
            return "";
        }
        return front->data;
    }
};

int main() {
    Queue q;
    int choice;
    std::string value;

    do {
        std::cout << "\nQueue Operations Menu:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Check if Queue is Empty\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter string to insert: ";
                std::cin.ignore();  // Ignore leftover newline from previous input
                std::getline(std::cin, value);
                q.insert(value);
                break;
            case 2:
                q.deleteElement();
                break;
            case 3:
                value = q.peek();
                if (!value.empty()) {
                    std::cout << "Front element is: \"" << value << "\"\n";
                }
                break;
            case 4:
                if (q.isEmpty()) {
                    std::cout << "Queue is empty.\n";
                } else {
                    std::cout << "Queue is not empty.\n";
                }
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
