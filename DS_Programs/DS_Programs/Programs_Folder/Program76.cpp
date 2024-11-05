// 11. CREATE A PROGRAM TO EVALUATE THE PREFIX EXPRESSION.

#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

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
        if (top < capacity - 1) {
            arr[++top] = x;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    // Function to remove the top element from the stack (pop)
    int pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return -9999; // Custom error value indicating underflow
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to perform an operation and return the result
int performOperation(int operand1, int operand2, char op) {
    int result = 0;  // Initialize result outside the switch statement
    switch (op) {
        case '+': 
            result = operand1 + operand2;
            break;
        case '-': 
            result = operand1 - operand2;
            break;
        case '*': 
            result = operand1 * operand2;
            break;
        case '/': 
            result = operand1 / operand2;
            break;
        case '^': 
            result = 1;
            for (int i = 0; i < operand2; i++) {
                result *= operand1;
            }
            break;
        default: 
            cout << "Invalid operator" << endl;
    }
    return result;
}

// Function to evaluate a prefix expression
int evaluatePrefix(const string& expression) {
    int length = expression.size();
    Stack stack(length);

    // Traverse the expression from right to left
    for (int i = length - 1; i >= 0; i--) {
        char ch = expression[i];

        // If the character is a digit (operand)
        if (isdigit(ch)) {
            // Convert character to integer and push it to stack
            stack.push(ch - '0');
        }
        // If the character is an operator
        else if (isOperator(ch)) {
            // Pop two operands from stack
            int operand1 = stack.pop();
            int operand2 = stack.pop();

            // Perform the operation and push the result back to stack
            int result = performOperation(operand1, operand2, ch);
            stack.push(result);
        }
    }

    // The final result will be at the top of the stack
    return stack.pop();
}

int main() {
    string expression;
    cout << "Enter a prefix expression: ";
    cin >> expression;

    int result = evaluatePrefix(expression);
    cout << "The result of the prefix expression is: " << result << endl;

    return 0;
}
