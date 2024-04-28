#include <iostream>
#include <queue> // Include the priority_queue header

int main() {
    // Creating a max heap (default behavior)
    std::priority_queue<int> maxHeap;

    // Creating a min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Inserting elements into the max heap
    maxHeap.push(3);
    maxHeap.push(5);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(2);

    // Inserting elements into the min heap
    minHeap.push(3);
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(2);

    // Accessing the top element (maximum for max heap, minimum for min heap)
    std::cout << "Max Heap Top: " << maxHeap.top() << std::endl;
    std::cout << "Min Heap Top: " << minHeap.top() << std::endl;

    // Removing the top element
    maxHeap.pop();
    minHeap.pop();

    // Printing the remaining elements
    std::cout << "Max Heap elements: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    std::cout << std::endl;

    std::cout << "Min Heap elements: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " ";
        minHeap.pop();
    }
    std::cout << std::endl;

    return 0;
}
/* OUTPUT
Max Heap Top: 5
Min Heap Top: 1
Max Heap elements: 4 3 2 1 
Min Heap elements: 2 3 4 5 
 */