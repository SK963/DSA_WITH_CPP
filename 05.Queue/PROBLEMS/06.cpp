#include <iostream>
#include <queue>
using namespace std;

struct Patient {
    int data;
    int priority;

    bool operator<(const Patient& other) const {
        return priority > other.priority; // Higher priority comes first
    }
};

int main() {
    int N;
    cin >> N;

    priority_queue<Patient> priorityQueue;

    for (int i = 0; i < N; ++i) {
        int data, priority;
        cin >> data >> priority;
        Patient patient = {data, priority};
        priorityQueue.push(patient);
    }

    cout << "Priority queue elements: ";
    while (!priorityQueue.empty()) {
        cout << priorityQueue.top().data << " ";
        priorityQueue.pop();
    }

    if (N == 0) {
        cout << "Prio";
    }

    cout << endl;

    return 0;
}
