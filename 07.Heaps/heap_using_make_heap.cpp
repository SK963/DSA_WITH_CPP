#include <iostream>
#include <algorithm> // Include the algorithm header
#include <vector>    // Include the vector header
using namespace std;

int main() 
{
    // Creating vectors for max heap and min heap
    vector<int> maxHeapVector = {3, 5, 1, 4, 2};
    vector<int> minHeapVector = {3, 5, 1, 4, 2};

    // Converting vectors into max and min heaps
    make_heap(maxHeapVector.begin(), maxHeapVector.end());
    make_heap(minHeapVector.begin(), minHeapVector.end(), greater<int>());

    // Accessing the top elements
    cout << "Max Heap Top: " << maxHeapVector.front() << endl;
    cout << "Min Heap Top: " << minHeapVector.front() << endl;

    // Inserting a new element into both heaps
    int newElement = 0;
    maxHeapVector.push_back(newElement);
    minHeapVector.push_back(newElement);

    push_heap(maxHeapVector.begin(), maxHeapVector.end());
    push_heap(minHeapVector.begin(), minHeapVector.end(), greater<int>());

    // Accessing the new top elements
    cout << "Max Heap Top after push: " << maxHeapVector.front() << endl;
    cout << "Min Heap Top after push: " << minHeapVector.front() << endl;

    // Removing the top elements
    pop_heap(maxHeapVector.begin(), maxHeapVector.end());
    int poppedMaxValue = maxHeapVector.back();
    maxHeapVector.pop_back();

    pop_heap(minHeapVector.begin(), minHeapVector.end(), greater<int>());
    int poppedMinValue = minHeapVector.back();
    minHeapVector.pop_back();

    // Printing the remaining elements
    cout << "Max Heap elements: ";
    for (int element : maxHeapVector) 
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "Min Heap elements: ";
    for (int element : minHeapVector) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Popped Max Element: " << poppedMaxValue << endl;
    cout << "Popped Min Element: " << poppedMinValue << endl;

    return 0;
}
