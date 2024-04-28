#include <iostream>

using namespace std;


struct node
{
    int data;
    struct node* link;
};

typedef node* Node;

Node getnode()
{
    Node x = new node;
    return x;
}

Node insertatfront(Node head, int item)
{
    Node temp = getnode();
    temp->data = item;

    if(head == NULL)
    {
        head = temp;
        head->link = head;
    }
    else
    {
        temp -> link = head-> link;
        head->link = temp;
        
    }
    head->data++;
    return head;
}

Node insertatend(Node head, int item)
{
    Node temp = getnode();
    temp->data = item;

    if(head == NULL)
    {
        head = temp;
        head->link = head;
    }
    else
    {
        Node cur = head->link;
        while(cur->link != head)
            {
                cur= cur->link;
            }
        temp->link = head;
        cur->link = temp;
    }
    head->data++;
    return head;
}

void display(Node head)
{
    Node temp;
    if(head ->link == head)
    {
        cout<<"list is empty";
        return;
    }
    cout<<"Number of nodes in the CLL:"<<endl;
    temp = head->link;
    while (temp != head)
        {
            cout<<temp->data<<" ";
            temp = temp->link;
        }
}

int main()
{
    Node head = NULL;
    int item, n;

    head = getnode();
    head->data = 0;
    head->link = head;

    cin>>n;

    for(int i = 0 ; i< n; i++)
        {
            cin>>item;
            head = insertatfront(head,item);
        }
    cin>>n;

    for(int i = 0; i< n; i++)
        {
            cin>>item;
            head = insertatend(head, item);
        }

    //display 
    display(head);
    return 0;
    
}