// CREATE A STACK IMPLEMENTING THE OPERATIONS ON THE CHARACTERS NODES (DYNAMICALLY) (PUSH, POP, PEEK, ISEMPTY, ISFULL)

#include <iostream>
using namespace std;

// Node structure for the stack
struct Node {
    char data;
    Node* next;
};

// Stack class implementing linked list
class CharStack {
private:
    Node* top; // Top of stack

public:
    // Constructor to initialize the stack
    CharStack() {
        top = nullptr;
    }

    // Destructor to free allocated memory
    ~CharStack() {
        while (top != nullptr) {
            pop();
        }
    }

    // Function to add an element to the stack (push)
    void push(char x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << "Pushed '" << x << "' to the stack." << endl;
    }

    // Function to remove the top element from the stack (pop)
    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return '\0'; // Return null character if stack is empty
        }
        char poppedData = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped '" << poppedData << "' from the stack." << endl;
        return poppedData;
    }

    // Function to return the top element of the stack (peek)
    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return '\0'; // Return null character if stack is empty
        }
        return top->data;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    CharStack stack;
    int choice;
    char value;

    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push
                cout << "Enter a character to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2: // Pop
                stack.pop();
                break;

            case 3: // Peek
                value = stack.peek();
                if (value != '\0') {
                    cout << "Top character is: '" << value << "'" << endl;
                }
                break;

            case 4: // Check if Empty
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5: // Exit
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
