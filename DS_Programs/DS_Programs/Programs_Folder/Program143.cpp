/*
Queue Reversal

Explanation -

Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue. Example 1: Input: 6 4 3 1 10 2 6 Output: 6 2 10 1 3 4 Explanation: After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4. Example 2: Input: 4 4 3 2 1 Output: 1 2 3 4 Explanation: After reversing the given elements of the queue , the resultant queue will be 1 2 3 4.
*/

#include <iostream>
#include <queue>
#include <stack>

void reverseQueue(std::queue<int>& q) {
    std::stack<int> s;

    // Step 1: Push all elements from the queue into the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Push all elements back from the stack into the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void printQueue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the queue: ";
    std::cin >> n;

    std::queue<int> q;
    std::cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        q.push(x);
    }

    reverseQueue(q);

    std::cout << "Queue after reversal: ";
    printQueue(q);

    return 0;
}
