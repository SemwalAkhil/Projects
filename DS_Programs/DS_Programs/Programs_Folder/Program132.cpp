// IMPLEMENT THE OPERATIONS OF PRIORITY QUEUE IN AN STRING ARRAY (INSERT, DELETE, PEEK, ISEMPTY, ISFULL)

#include <iostream>
#include <string>
#define MAX 5  // Define the maximum size of the priority queue

class PriorityQueue {
private:
    std::string arr[MAX];  // Array to store queue elements
    int count;             // Number of elements in the queue

public:
    PriorityQueue() : count(0) {}

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return count == MAX;
    }

    // Function to insert a string into the priority queue
    void insert(const std::string& value) {
        if (isFull()) {
            std::cout << "Queue is full. Cannot insert \"" << value << "\".\n";
            return;
        }

        // Find the correct position for the new element
        int i;
        for (i = count - 1; i >= 0 && arr[i] < value; i--) {
            arr[i + 1] = arr[i];  // Shift elements to make space for new element
        }

        arr[i + 1] = value;
        count++;
        std::cout << "Inserted \"" << value << "\" into the queue.\n";
    }

    // Function to delete the element with the highest priority
    void deleteElement() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot delete.\n";
            return;
        }
        std::cout << "Deleted \"" << arr[0] << "\" from the queue.\n";

        // Shift all elements one position to the left
        for (int i = 1; i < count; i++) {
            arr[i - 1] = arr[i];
        }
        count--;
    }

    // Function to get the element with the highest priority
    std::string peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Nothing to peek.\n";
            return "";
        }
        return arr[0];
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    std::string value;

    do {
        std::cout << "\nPriority Queue Operations Menu:\n";
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
                pq.insert(value);
                break;
            case 2:
                pq.deleteElement();
                break;
            case 3:
                value = pq.peek();
                if (!value.empty()) {
                    std::cout << "Highest priority element is: \"" << value << "\"\n";
                }
                break;
            case 4:
                if (pq.isEmpty()) {
                    std::cout << "Queue is empty.\n";
                } else {
                    std::cout << "Queue is not empty.\n";
                }
                break;
            case 5:
                if (pq.isFull()) {
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
