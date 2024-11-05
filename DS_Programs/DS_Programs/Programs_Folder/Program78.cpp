// IMPLEMENT THE TOWER OF HANOI USING STACKS

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

// Function to move a disk from one stack to another and print the move
void moveDisk(stack<int>& source, stack<int>& destination, char s, char d) {
    // Check if the source stack is empty
    if (source.empty()) {
        int topDisk = destination.top();
        destination.pop();
        source.push(topDisk);
        cout << "Move disk " << topDisk << " from " << d << " to " << s << endl;
    }
    // Check if the destination stack is empty
    else if (destination.empty()) {
        int topDisk = source.top();
        source.pop();
        destination.push(topDisk);
        cout << "Move disk " << topDisk << " from " << s << " to " << d << endl;
    }
    // If neither stack is empty, compare the top disks
    else if (source.top() > destination.top()) {
        int topDisk = destination.top();
        destination.pop();
        source.push(topDisk);
        cout << "Move disk " << topDisk << " from " << d << " to " << s << endl;
    } else {
        int topDisk = source.top();
        source.pop();
        destination.push(topDisk);
        cout << "Move disk " << topDisk << " from " << s << " to " << d << endl;
    }
}

// Function to solve Tower of Hanoi using three stacks
void towerOfHanoi(int num_disks) {
    stack<int> source, auxiliary, destination;
    char s = 'S', a = 'A', d = 'D';

    // Push disks onto the source stack in decreasing order
    for (int i = num_disks; i >= 1; i--) {
        source.push(i);
    }

    int total_moves = pow(2, num_disks) - 1;

    // If the number of disks is even, swap the destination and auxiliary
    if (num_disks % 2 == 0) {
        swap(d, a);
    }

    // Perform the moves
    for (int i = 1; i <= total_moves; i++) {
        if (i % 3 == 1) {
            moveDisk(source, destination, s, d);
        } else if (i % 3 == 2) {
            moveDisk(source, auxiliary, s, a);
        } else if (i % 3 == 3) {
            moveDisk(auxiliary, destination, a, d);
        }
    }
}

int main() {
    int num_disks;
    cout << "Enter the number of disks: ";
    cin >> num_disks;

    cout << "The moves are:" << endl;
    towerOfHanoi(num_disks);

    return 0;
}
