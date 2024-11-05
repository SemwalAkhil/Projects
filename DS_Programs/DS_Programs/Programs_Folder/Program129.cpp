// IMPLEMENT THE OPERATIONS OF CIRCULAR QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)

#include <iostream>
#define MAX 5  // Define the maximum size of the circular queue

class CircularQueue {
private:
    int arr[MAX];  // Array to store queue elements
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int count;     // Number of elements in the queue

public:
    CircularQueue() : front(0), rear(0), count(0) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return count == MAX;
    }

    // Function to insert an element into the circular queue
    void insert(int value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot insert " << value << ".\n";
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % MAX;  // Move rear to the next position circularly
        count++;
        std::cout << "Inserted " << value << " into the queue.\n";
    }

    // Function to delete an element from the circular queue
    void deleteElement() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot delete.\n";
            return;
        }
        std::cout << "Deleted " << arr[front] << " from the queue.\n";
        front = (front + 1) % MAX;  // Move front to the next position circularly
        count--;
    }

    // Function to get the front element of the circular queue
    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Nothing to peek.\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        std::cout << "\nCircular Queue Operations Menu:\n";
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
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                cq.insert(value);
                break;
            case 2:
                cq.deleteElement();
                break;
            case 3:
                value = cq.peek();
                if (value != -1) {
                    std::cout << "Front element is: " << value << "\n";
                }
                break;
            case 4:
                if (cq.isEmpty()) {
                    std::cout << "Queue is empty.\n";
                } else {
                    std::cout << "Queue is not empty.\n";
                }
                break;
            case 5:
                if (cq.isFull()) {
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
