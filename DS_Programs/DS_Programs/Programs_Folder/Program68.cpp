// CREATE A STACK IMPLEMENTING THE OPERATIONS ON AN INTEGER NODES (DYNAMICALLY) (PUSH, POP, PEEK, ISEMPTY, ISFULL)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << x << " to the stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return -1;
        }
        int poppedData = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped " << poppedData << " from the stack." << endl;
        return poppedData;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;
    int choice, value;

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
