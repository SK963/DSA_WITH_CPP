#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;

public:
    PriorityQueue() {
        size = 0;
    }

    void enqueue(int element, int priority) {
        if (size == MAX_SIZE) {
            cout << "Priority Queue is full." << endl;
            return;
        }

        int i = size;
        while (i > 0 && priority < priorities[i - 1]) {
            elements[i] = elements[i - 1];
            priorities[i] = priorities[i - 1];
            i--;
        }

        elements[i] = element;
        priorities[i] = priority;
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        for (int i = 0; i < size - 1; i++) {
            elements[i] = elements[i + 1];
            priorities[i] = priorities[i + 1];
        }

        size--;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void printPriorityQueue() {
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int element, priority;
        cin >> element >> priority;
        pq.enqueue(element, priority);
    }

    cout << "Priority Queue: ";
    pq.printPriorityQueue();

    pq.dequeue();
    
    cout << "Priority Queue: ";
    pq.printPriorityQueue();

    return 0;
}
