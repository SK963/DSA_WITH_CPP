#include <iostream>
#include <string>

using namespace std;
// --------
//defining a node structurea
struct node
{
string data;
node* next;
};

struct node* start = nullptr;


//creating new node
node* createnode(const string& data)
{
node* newnode = new node;
newnode ->data = data;
newnode->next = NULL;
return newnode;  
}

struct nod* create_header(const string& data)
{
    //create a new node
    struct nod* new_node , *node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node ->data  = data;
    new_node ->link = nullpptr;

    //
    if(start == nullptr)
    {
        start - (struct node*)malloc(sizeof(struct node));
        start->link = next;
        
    }
    else
    {
        node = start;
        
        
    }
}
// --------

// function to insert a node at the specified position in the ll
void insertnode(node** head , const string& data , int pos)
{
    node* newnode = createnode(data);
    if(pos == 1) //for position = 1 , make new node / or head
    {
        newnode-> next = *head;
        *head = newnode;
    }
    else 
    {
        node* temp = *head;
        for(int i= 1 ; i < pos-1 && temp != NULL ; i++)
            {
                temp = temp->next;
            }
        if(temp == NULL)    
        {
            node* lastnode = *head;
            while(lastnode->next != NULL)
                {
                    lastnode = lastnode->next;
                }
            lastnode->next = newnode;
        }
        else
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

//function to print ll

void displaylist(node* head)
{
    node* temp = head;
    while(temp!= NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
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
            insertnode(&head, data, i);
        }

    
    cout<<"current linked list:- "<<endl;
    displaylist(head);
    cout<<"enter the data item to be inserted :-";
    cin>>data;

    
    
   
    insertnode(&head, data , n+1);
    cout<<"Updated linked list:- ";
    displaylist(head);
   
    return 0;
}