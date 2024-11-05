// CREATE THE PROGRAM TO MATCH THE SINGLE BRACKET USING STACKS

#include <iostream>
using namespace std;

class CharStack {
private:
    int top;
    int capacity;
    char* arr;

public:
    // Constructor to initialize the stack
    CharStack(int size) {
        capacity = size;
        arr = new char[size];
        top = -1;
    }

    // Destructor to free allocated memory
    ~CharStack() {
        delete[] arr;
    }

    // Function to push a character onto the stack
    void push(char ch) {
        if (top < capacity - 1) {
            arr[++top] = ch;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    // Function to pop a character from the stack
    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

bool isBalanced(string expression) {
    int n = expression.length();
    CharStack stack(n);

    for (char ch : expression) {
        if (ch == '(') {
            stack.push(ch);  // Push opening bracket onto stack
        } else if (ch == ')') {
            if (stack.isEmpty()) {
                // If a closing bracket is found and stack is empty, it's unbalanced
                return false;
            }
            stack.pop();  // Pop matching opening bracket
        }
    }

    // If stack is empty after processing, all brackets were matched
    return stack.isEmpty();
}

int main() {
    string expression;
    cout << "Enter an expression with single brackets: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "The expression is balanced." << endl;
    } else {
        cout << "The expression is not balanced." << endl;
    }

    return 0;
}
