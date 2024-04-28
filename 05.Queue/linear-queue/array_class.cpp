// Implementation of queue(enqueue, dequeue).
#include <bits/stdc++.h>
using namespace std;

class Queue 
{
public:
	int front, rear, size;
	unsigned cap;
	int* arr;
};

Queue* createQueue(unsigned cap)
{
	Queue* queue = new Queue();
	queue->cap = cap;
	queue->front = queue->size = 0;

	queue->rear = cap - 1;
	queue->arr = new int[(queue->cap * sizeof(int))];
	return queue;
}

int isFull(Queue* queue)
{
	return (queue->size == queue->cap);
}

int isempty(Queue* queue) 
{
    return (queue->size == 0); 
}
// Function to add an item to the queue.
// It changes rear and size.

void enqueue(Queue* queue, int item)
{
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->cap;
	queue->arr[queue->rear] = item;
	queue->size = queue->size + 1;
	cout << item << " enqueued to queue\n";
}
// Function to remove an item from queue.
// It changes front and size
void dequeue(Queue* queue)
{
	if (isempty(queue))
    {
		cout<<"empty queue"<<endl;
        return;
    }    
	int item = queue->arr[queue->front];
	queue->front = (queue->front + 1) % queue->cap;
	queue->size = queue->size - 1;
    cout<<item<<" dequed successfully"<<endl;
    
	// return item;
}

int front(Queue* queue)
{
	if (isempty(queue))
		return INT_MIN;
	return queue->arr[queue->front];
}

int rear(Queue* queue)
{
	if (isempty(queue))
		return INT_MIN;
	return queue->arr[queue->rear];
}

void showq(Queue *queue)
{
    
    cout<<"the queue is :- ";
    for(int i = queue->front ; i <= queue->rear ;i++)
        {
            cout<< queue->arr[i]<<" ";
        }
    cout<<endl;
    
}

// Driver code
int main()
{
	Queue* queue = createQueue(10);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
    showq(queue);
	dequeue(queue);
    showq(queue);
	
	cout << "Front item is " << front(queue) << endl;
	cout << "Rear item is " << rear(queue)<<endl;
	return 0;
}
