// CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER ARRAY (PUSH, POP, PEEK, ISEMPTY, ISFULL)

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;       // Array to store stack elements
    int top;        // Top of stack
    int capacity;   // Maximum capacity of the stack

public:
    // Constructor to initialize the stack
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Function to add an element to the stack (push)
    void push(int x) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << "Pushed " << x << " to the stack." << endl;
    }

    // Function to remove the top element from the stack (pop)
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return -1;
        }
        cout << "Popped " << arr[top] << " from the stack." << endl;
        return arr[top--];
    }

    // Function to return the top element of the stack (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -1;
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);
    int choice, value;

    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push
                cout << "Enter a value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2: // Pop
                stack.pop();
                break;

            case 3: // Peek
                value = stack.peek();
                if (value != -1) {
                    cout << "Top element is: " << value << endl;
                }
                break;

            case 4: // Check if Empty
                if (stack.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;

            case 5: // Check if Full
                if (stack.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;

            case 6: // Exit
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
