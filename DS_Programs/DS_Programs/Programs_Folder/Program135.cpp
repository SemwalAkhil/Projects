//  IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE DYNAMICALLY OF INTEGERS (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* front;  // Pointer to the highest priority element

public:
    PriorityQueue() : front(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert an element into the priority queue
    void insert(int value) {
        Node* newNode = new Node(value);

        // If queue is empty or new node has higher priority
        if (isEmpty() || front->data < value) {
            newNode->next = front;
            front = newNode;
        } else {
            // Find the correct position to insert
            Node* temp = front;
            while (temp->next != nullptr && temp->next->data >= value) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        std::cout << "Inserted " << value << " into the priority queue.\n";
    }

    // Delete the element with the highest priority
    void deleteElement() {
        if (isEmpty()) {
            std::cout << "Priority queue is empty. Cannot delete.\n";
            return;
        }
        Node* temp = front;
        std::cout << "Deleted " << front->data << " from the priority queue.\n";
        front = front->next;
        delete temp;
    }

    // Peek at the element with the highest priority
    int peek() {
        if (isEmpty()) {
            std::cout << "Priority queue is empty. Nothing to peek.\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    do {
        std::cout << "\nPriority Queue Operations Menu:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Peek\n";
        std::cout << "4. Check if Queue is Empty\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                pq.insert(value);
                break;
            case 2:
                pq.deleteElement();
                break;
            case 3:
                value = pq.peek();
                if (value != -1) {
                    std::cout << "Highest priority element is: " << value << "\n";
                }
                break;
            case 4:
                if (pq.isEmpty()) {
                    std::cout << "Priority queue is empty.\n";
                } else {
                    std::cout << "Priority queue is not empty.\n";
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
