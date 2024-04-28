#include <iostream>
using namespace std;

const int maxCapacity = 5;

class Queue {
private:
    int front, rear, count;
    int elements[maxCapacity];

public:
    Queue() {
        front = rear = count = 0;
    }

    void enqueue(int item) {
        if (count >= maxCapacity) {
            cout << "Queue is full." << endl;
            return;
        }
        elements[rear] = item;
        rear = (rear + 1) % maxCapacity;
        count++;
        cout << item << " is inserted in the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        int item = elements[front];
        front = (front + 1) % maxCapacity;
        count--;
        cout << "Deleted number is: " << item << endl;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == maxCapacity;
    }

    void displayQueue() {
        cout << "Elements in the queue are: ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << elements[i] << " ";
            i = (i + 1) % maxCapacity;
        }
        cout << endl;
    }
};

int main() {
    Queue ticketQueue;

    int option, number;
    bool invalidOptionPrinted = false;

    while (true) {
        cin >> option;

        if (option == 1) {
            cin >> number;
            ticketQueue.enqueue(number);
        } else if (option == 2) {
            ticketQueue.dequeue();
        } else if (option == 3) {
            ticketQueue.displayQueue();
        } else if (option == 4) {
            break;
        } else {
            if (!invalidOptionPrinted) {
                cout << "Invalid option." << endl;
                invalidOptionPrinted = true;
            }
        }
    }

    return 0;
}
