// ENTER THE STRING FROM THE USER AND REVERSE THE STRING USING STACKS

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

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int n = input.length();
    CharStack stack(n);

    // Push each character of the string onto the stack
    for (char ch : input) {
        stack.push(ch);
    }

    // Pop characters from the stack to form the reversed string
    string reversed;
    while (!stack.isEmpty()) {
        reversed += stack.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
