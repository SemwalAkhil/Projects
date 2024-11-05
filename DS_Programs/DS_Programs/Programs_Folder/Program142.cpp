/*
Reverse First K elements of Queue

Explanation -

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order. Only following standard operations are allowed on queue. enqueue(x) : Add an item x to rear of queue dequeue() : Remove an item from front of queue size() : Returns number of elements in queue. front() : Finds front item. Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem. Example 1: Input: 5 3 1 2 3 4 5 Output: 3 2 1 4 5 Explanation: After reversing the given input from the 3rd position the resultant output will be 3 2 1 4 5. Example 2: Input: 4 4 4 3 2 1 Output: 1 2 3 4 Explanation: After reversing the given input from the 4th position the resultant output will be 1 2 3 4.
*/

#include <iostream>
#include <queue>
#include <stack>

void reverseFirstKElements(std::queue<int>& q, int k) {
    if (q.empty() || k > q.size() || k <= 0) {
        return; // Invalid case, do nothing
    }

    std::stack<int> s;

    // Step 1: Push the first K elements into the stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the stack elements back to the queue (reversed order)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining elements from the front to the rear to maintain order
    int size = q.size();
    for (int i = 0; i < size - k; i++) {
        q.push(q.front());
        q.pop();
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
    int n, k;
    std::cout << "Enter the number of elements in the queue: ";
    std::cin >> n;

    std::queue<int> q;
    std::cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        q.push(x);
    }

    std::cout << "Enter the value of K: ";
    std::cin >> k;

    reverseFirstKElements(q, k);

    std::cout << "Queue after reversing first " << k << " elements: ";
    printQueue(q);

    return 0;
}
