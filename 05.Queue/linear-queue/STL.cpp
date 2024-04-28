#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a queue of integers
    queue<int> myQueue;

    // Enqueue (push) elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Check if the queue is empty
    if (myQueue.empty()) {
        cout << "Queue is empty.\n";
    } else {
        cout << "Queue is not empty.\n";
    }

    // Get the size of the queue
    cout << "Size of the queue: " << myQueue.size() << "\n";

    // Access the front element without dequeuing
    cout << "Front element: " << myQueue.front() << "\n";

    // Dequeue elements from the queue
    myQueue.pop();

    // Print elements after dequeuing
    cout << "Elements after dequeuing:\n";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << "\n";

    return 0;
}
