#include <iostream>
using namespace std;

class QNode 
{
    public:
	int data;
	QNode* link;

	QNode(int data):data(data) , link(NULL){}
};

class Queue 
{
    public:
	QNode *front, *rear;
	Queue() 
    {
        front = rear = NULL; 
    }

	void enQueue(int value)
	{

		// Create a new LL node
		QNode* new_node = new QNode(value);

		// If queue is empty, then
		// new node is front and rear both
		if(rear == NULL)
        {
			front = rear = new_node;
			return;
		}

		// Add the new node at
		// the end of queue and change rear
		rear->link = new_node;
		rear = new_node;
	}

	void deQueue()
	{
		// If queue is empty, return NULL.
		if (front == NULL)
        {
            cout<<"the queue is empty"<<endl;
            return;
        }
		
		// Store previous front and
		// move front one node ahead
		QNode *temp = front;
		front = front->link;

		// If front becomes NULL, then
		// change rear also as NULL
		if (front == NULL)
			rear = NULL;

		delete (temp);
	}

    void showQueue()
    {
        QNode *temp = front;
        while(temp != NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->link;
            }
        cout<<endl;
    
    }
};

// Driver code
int main()
{
    Queue q;
    int temp = 0;
    while(temp >= 0)
        {
            cout<<"enter the next element:- ";
            cin>>temp;
            if(temp > 0)
            {
                q.enQueue(temp);
            }
            else
                q.showQueue();
        }


	// cout << "Queue Front : " << ((q.front != NULL) ? (q.front)->data : -1)<< endl;
	// cout << "Queue Rear : " << ((q.rear != NULL) ? (q.rear)->data : -1);
}

