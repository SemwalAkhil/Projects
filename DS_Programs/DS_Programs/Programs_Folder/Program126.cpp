//IMPLEMENT THE OPERATIONS OF SIMPLE QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)

#include <iostream>
#define MAX 5  // Define the maximum size of the queue

class Queue {
private:
    std::string arr[MAX];  // Array to store the queue elements
    int front;             // Index of the front element
    int rear;              // Index of the rear element

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Function to insert a string into the queue
    void insert(const std::string& value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot insert \"" << value << "\".\n";
            return;
        }
        if (isEmpty()) {
            front = 0;  // Initialize front if queue was empty
        }
        arr[++rear] = value;
        std::cout << "Inserted \"" << value << "\" into the queue.\n";
    }

    // Function to delete a string from the queue
    void deleteElement() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot delete.\n";
            return;
        }
        std::cout << "Deleted \"" << arr[front] << "\" from the queue.\n";
        if (front == rear) {  // Queue becomes empty after deletion
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Function to get the front element of the queue
    std::string peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Nothing to peek.\n";
            return "";
        }
        return arr[front];
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
        std::cout << "5. Check if Queue is Full\n";
        std::cout << "6. Exit\n";
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
                if (q.isFull()) {
                    std::cout << "Queue is full.\n";
                } else {
                    std::cout << "Queue is not full.\n";
                }
                break;
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
