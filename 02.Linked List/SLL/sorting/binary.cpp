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




// --------

// function to insert a node at the specified position in the ll
void insertatbegining(node** head , const string& data )
{
    //creating new node and inserting data into it
    node* newnode = new node;
    newnode ->data = data;
    newnode->link = *head;

    *head = newnode;

}

//function to print ll

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

void ascend(node *head)
{
    node *prev = head;
    node *curr = head;
    node *next = curr->link;
    
    while(curr != NULL)
        {
            
            if(curr->data > next->data)
            {
                if(curr == head)
                {
                    head = next;
                    curr
                   
                    
                }
                else
                {
                    
                }
            }
            
            
        }
    
    
    
}

int main() 
{
    int size , pos ;
    
    string data;
    
    node* head = NULL;
    
    cout<<"enter the size for linked list :- ";
    cin>>size;
    
    for(int i = 1 ; i <= size ; i++)
        {
            cin>>data;
            insertatbegining(&head, data);
        }

    
    cout<<"linked list:- "<<endl;
    displaylist(head);
  
    return 0;
}