#include <iostream>
#include <string>

using namespace std;
// --------
//defining a node structurea
struct node
{
string data;
node* link;
};




// function to insert a node at the specified position in the ll
void insertatpos(node** head , const string& data , int pos)
{

    node* newnode = new node;
    newnode ->data = data;
    newnode->link = NULL;

    // head node
    if(pos == 1) //insertion at front
    {
        newnode-> link = *head;
        *head = newnode;
    }
    else 
    {
        node* temp = *head;
        for(int i= 1 ; i < pos-1 && temp != NULL ; i++)
            {
                temp = temp->link;
            }
        //reach the n-1 th node link 
        if(temp == NULL)//insertion at end if link of n-1 th node is empty
        {
            node* lastnode = *head;
            while(lastnode->link != NULL)
                {
                    lastnode = lastnode->link;
                }
            lastnode->link = newnode;
        }
        else//inserton at nth position if it points to some other node
        {
            newnode->link = temp->link;//point the new node link to n+1 node
            temp->link = newnode; //point the n-1 node to new node
        }
    }
}

//function to print LL
void displaylist(node* head)
{
    node* temp = head;
    while(temp!= NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->link;
        }
    cout<<endl;
}

int main() 
{
    int n , pos ;
    string data;

    
    node* head = NULL;

    
    cout<<"enter the size for linked list :- ";
    cin>>n;

    
    for(int i = 1 ; i <= n ; i++)
        {
            cin>>data;
            insertatpos(&head, data, i);
        }


    //
    cout<<"current linked list:- "<<endl;
    displaylist(head);

    
    cout<<"enter the data item to be inserted :-";
    cin>>data;
    cout<<"enter the position for the node:- ";
    cin>>pos;

    
    if(pos > n+1 )
    {
        cout<<"Invalid position "<<endl;
    }
    else
    {
        insertnode(&head, data , pos);
        cout<<"Updated linked list:- ";
        displaylist(head);
    }
    
    displaylist(head);
    return 0;
}