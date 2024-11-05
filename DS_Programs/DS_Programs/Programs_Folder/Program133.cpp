// IMPLEMENT THE OPERATIONS OF DOUBLE ENDED QUEUE IN AN INTEGER ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)

#include <iostream>
#define MAX 5  // Define the maximum size of the deque

class Deque {
private:
    int arr[MAX];
    int front;
    int rear;
    int count;

public:
    Deque() : front(0), rear(0), count(0) {}

    // Check if the deque is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return count == MAX;
    }

    // Insert an element at the front of the deque
    void insertFront(int value) {
        if (isFull()) {
            std::cout << "Deque is full. Cannot insert at the front.\n";
            return;
        }
        front = (front - 1 + MAX) % MAX;  // Wrap around to the end if needed
        arr[front] = value;
        count++;
        std::cout << "Inserted " << value << " at the front.\n";
    }

    // Insert an element at the rear of the deque
    void insertRear(int value) {
        if (isFull()) {
            std::cout << "Deque is full. Cannot insert at the rear.\n";
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % MAX;  // Wrap around to the front if needed
        count++;
        std::cout << "Inserted " << value << " at the rear.\n";
    }

    // Delete an element from the front of the deque
    void deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from the front.\n";
            return;
        }
        std::cout << "Deleted " << arr[front] << " from the front.\n";
        front = (front + 1) % MAX;  // Move front forward
        count--;
    }

    // Delete an element from the rear of the deque
    void deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Cannot delete from the rear.\n";
            return;
        }
        rear = (rear - 1 + MAX) % MAX;  // Move rear backward, wrapping around
        std::cout << "Deleted " << arr[rear] << " from the rear.\n";
        count--;
    }

    // Get the front element of the deque
    int peekFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Nothing at the front to peek.\n";
            return -1;
        }
        return arr[front];
    }

    // Get the rear element of the deque
    int peekRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty. Nothing at the rear to peek.\n";
            return -1;
        }
        return arr[(rear - 1 + MAX) % MAX];  // Rear points to next empty position
    }
};

int main() {
    Deque dq;
    int choice, value;

    do {
        std::cout << "\nDouble-Ended Queue Operations Menu:\n";
        std::cout << "1. Insert at Front\n";
        std::cout << "2. Insert at Rear\n";
        std::cout << "3. Delete from Front\n";
        std::cout << "4. Delete from Rear\n";
        std::cout << "5. Peek at Front\n";
        std::cout << "6. Peek at Rear\n";
        std::cout << "7. Check if Deque is Empty\n";
        std::cout << "8. Check if Deque is Full\n";
        std::cout << "9. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert at front: ";
                std::cin >> value;
                dq.insertFront(value);
                break;
            case 2:
                std::cout << "Enter value to insert at rear: ";
                std::cin >> value;
                dq.insertRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                value = dq.peekFront();
                if (value != -1) {
                    std::cout << "Front element is: " << value << "\n";
                }
                break;
            case 6:
                value = dq.peekRear();
                if (value != -1) {
                    std::cout << "Rear element is: " << value << "\n";
                }
                break;
            case 7:
                if (dq.isEmpty()) {
                    std::cout << "Deque is empty.\n";
                } else {
                    std::cout << "Deque is not empty.\n";
                }
                break;
            case 8:
                if (dq.isFull()) {
                    std::cout << "Deque is full.\n";
                } else {
                    std::cout << "Deque is not full.\n";
                }
                break;
            case 9:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
