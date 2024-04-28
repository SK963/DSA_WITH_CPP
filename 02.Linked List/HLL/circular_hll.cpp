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

Node deleteatpostion(Node head , int postion)
{
    if(head == NULL)
    {
        cout<<"List is empty."<<endl;
        return NULL;
    }
    Node cur = head;
    Node prev = NULL ;
    int count = 1;

    while (cur->link != head && count <postion)
        {
            prev = cur;
            cur = cur->link;
            count++;
            
        }

    if(count<postion)
    {
        cout<<"Invalid position."<<endl;
        return head;
    }

    if (prev == NULL)
    {
        Node last = head;
        while(last->link != head)
            {
                last = last ->link;
            }
        last->link = head->link;
        head - head->link;
        
    }
    else
        {
        prev->link = cur->link;
        }

    delete cur;
    return head;
        
}

int main()
{
    Node head = NULL;
    int item, n , postion;

    head = getnode();
    head->data = 0;
    head->link = head;

    cout<<"enter the size of the ll:- ";
    cin>>n;

    if(n>0)
    {
    for(int i = 0 ; i< n; i++)
        {
            cin>>item;
            head = insertatend(head,item);
        }
        
    
    //display 
    cout<<"the original ll:- ";
    display(head);

    cout<<"enter the postion of the element to be deleted :- ";
    cin>>postion;
    if(postion <=n)
    {
        head = deleteatpostion(head,postion);
        cout<<"ll after detetion:- ";
        display(head);
        
    }
    else
    {
        cout<<"Invalid postion"<<endl;
    }

    }  
    else
    {
        cout<<"List is empty";
    }
    return 0;
    
}