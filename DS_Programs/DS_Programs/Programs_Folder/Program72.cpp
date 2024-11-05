// CREATE TWO INTEGER STACKS IN A SINGLE ARRAY

#include <iostream>
using namespace std;

class TwoStacks {
private:
    int* arr;      // Array to store stack elements
    int capacity;  // Maximum capacity of the array
    int top1;      // Top of stack 1
    int top2;      // Top of stack 2

public:
    // Constructor to initialize the two stacks
    TwoStacks(int size) {
        capacity = size;
        arr = new int[size];
        top1 = -1;            // Stack 1 starts from the beginning
        top2 = size;          // Stack 2 starts from the end
    }

    // Destructor to free allocated memory
    ~TwoStacks() {
        delete[] arr;
    }

    // Function to push an element to Stack 1
    void push1(int x) {
        if (top1 < top2 - 1) {  // Check for space
            arr[++top1] = x;
            cout << "Pushed " << x << " to Stack 1." << endl;
        } else {
            cout << "Stack 1 overflow!" << endl;
        }
    }

    // Function to push an element to Stack 2
    void push2(int x) {
        if (top1 < top2 - 1) {  // Check for space
            arr[--top2] = x;
            cout << "Pushed " << x << " to Stack 2." << endl;
        } else {
            cout << "Stack 2 overflow!" << endl;
        }
    }

    // Function to pop an element from Stack 1
    int pop1() {
        if (top1 >= 0) {
            int x = arr[top1--];
            cout << "Popped " << x << " from Stack 1." << endl;
            return x;
        } else {
            cout << "Stack 1 underflow!" << endl;
            return -1;
        }
    }

    // Function to pop an element from Stack 2
    int pop2() {
        if (top2 < capacity) {
            int x = arr[top2++];
            cout << "Popped " << x << " from Stack 2." << endl;
            return x;
        } else {
            cout << "Stack 2 underflow!" << endl;
            return -1;
        }
    }

    // Function to check if Stack 1 is empty
    bool isEmpty1() {
        return top1 == -1;
    }

    // Function to check if Stack 2 is empty
    bool isEmpty2() {
        return top2 == capacity;
    }

    // Function to check if the array is full
    bool isFull() {
        return top1 == top2 - 1;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array for the two stacks: ";
    cin >> size;

    TwoStacks stacks(size);
    int choice, stackNumber, value;

    while (true) {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Push to Stack 1" << endl;
        cout << "2. Push to Stack 2" << endl;
        cout << "3. Pop from Stack 1" << endl;
        cout << "4. Pop from Stack 2" << endl;
        cout << "5. Check if Stack 1 is Empty" << endl;
        cout << "6. Check if Stack 2 is Empty" << endl;
        cout << "7. Check if Array is Full" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push to Stack 1
                cout << "Enter a value to push to Stack 1: ";
                cin >> value;
                stacks.push1(value);
                break;

            case 2: // Push to Stack 2
                cout << "Enter a value to push to Stack 2: ";
                cin >> value;
                stacks.push2(value);
                break;

            case 3: // Pop from Stack 1
                stacks.pop1();
                break;

            case 4: // Pop from Stack 2
                stacks.pop2();
                break;

            case 5: // Check if Stack 1 is Empty
                if (stacks.isEmpty1()) {
                    cout << "Stack 1 is empty." << endl;
                } else {
                    cout << "Stack 1 is not empty." << endl;
                }
                break;

            case 6: // Check if Stack 2 is Empty
                if (stacks.isEmpty2()) {
                    cout << "Stack 2 is empty." << endl;
                } else {
                    cout << "Stack 2 is not empty." << endl;
                }
                break;

            case 7: // Check if Array is Full
                if (stacks.isFull()) {
                    cout << "The array is full." << endl;
                } else {
                    cout << "The array is not full." << endl;
                }
                break;

            case 8: // Exit
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
