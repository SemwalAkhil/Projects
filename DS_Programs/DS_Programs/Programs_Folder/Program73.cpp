// SORT THE STACK IN ASCENDING ORDER USING INTEGER ARRAY

#include <iostream>
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
            cout << "Stack underflow! Cannot pop." << endl;
            return -9999; // Custom error value indicating underflow
        }
    }

    // Function to return the top element of the stack (peek)
    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -9999; // Custom error value indicating the stack is empty
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Function to sort the stack in ascending order
    void sortStack() {
    Stack tempStack(capacity);

    while (!isEmpty()) {
        // Pop the top element from the original stack
        int current = pop();

        // Move elements from tempStack back to the original stack if they are greater than the current element
        while (!tempStack.isEmpty() && tempStack.peek() > current) {
            push(tempStack.pop());
        }

        // Push the current element into the tempStack
        tempStack.push(current);
    }

    // Transfer sorted elements back to the original stack
    while (!tempStack.isEmpty()) {
        push(tempStack.pop());
    }
}


    // Function to display elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);

    cout << "Enter " << size << " elements to push to the stack:" << endl;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        stack.push(value);
    }

    cout << "Stack before sorting: ";
    stack.display();

    stack.sortStack();

    cout << "Stack after sorting in descending order: ";
    stack.display();

    return 0;
}
