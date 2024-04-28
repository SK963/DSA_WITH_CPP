#include <iostream>
#include <string>
using namespace std;

struct node
{
    string data;
    struct node* link;
};

//creating new node
node* createnode(const string& data)
{
node* newnode = new node;
newnode ->data = data;
newnode->link = NULL;
return newnode;  
}

//insert 
void insertnode(node** head , const string& data , int pos)
{
    node* newnode = createnode(data);
    if(pos == 1) //for position = 1 , make new node / or head
    {
        newnode->link = *head;
        *head = newnode;
    }
    else 
    {
        node* temp = *head;
        for(int i= 1 ; i < pos-1 && temp != NULL ; i++)
            {
                temp = temp->link;
            }
        if(temp == NULL)
        {
            node* lastnode = *head;
            while(lastnode->link != NULL)
                {
                    lastnode = lastnode->link;
                }
            lastnode->link = newnode;
        }
        else
        {
            newnode->link = temp->link;
            temp->link = newnode;
        }
    }
}

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

//delete
void deletenode(struct node** head , const string& key)
{
    struct node *temp = *head , *prev;

    if(temp != nullptr && temp->data == key)
    {
        *head = temp->link;
        free(temp);
        return;
    }

    while(temp != nullptr && temp->data != key)
        {
            prev = temp;
            temp= temp->link;
        }

    if(temp == nullptr)
        return;

    prev->link = temp->link;

    free(temp);
}


int main() 
{
    int n ;
    string data , key;
    node* head = NULL;
    cout<<"enter the size for linked list :- ";
    cin>>n;
    
    for(int i = 1 ; i <= n ; i++)
        {
            cin>>data;
            insertnode(&head, data, i);
        }

    
    cout<<"current linked list:- "<<endl;
    displaylist(head);
    
    cout<<"enter the node item to be deleted :-";
    cin>>key;
    
    deletenode(&head , key);
    cout<<"the updated list :- ";
    displaylist(head);
    
    return 0;
}