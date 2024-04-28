
#include <iostream>
#include <string>

using namespace std;


struct node
{
string data;
node* link;
};

void insertnode(node** head , const string& data)
{
    //creating new node and data insertion in node
    node* newnode = new node;
    newnode ->data = data;
    newnode->link = NULL;


    //if LL is empty
    if(*head == NULL)
    {
        *head = newnode;
    }
    else
    {
		node *ptr = *head;
		while(ptr->link != NULL)
		{
				ptr= ptr->link;
		}

		ptr->link = newnode;
    }

}    


//display LL
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
    int n ;
    string data;
    node* head = NULL;
    cout<<"enter the size for linked list :- ";
    cin>>n;
    
    for(int i = 1 ; i <= n ; i++)
        {
            cin>>data;
            insertnode(&head, data);
        }

    
    cout<<"linked list:- "<<endl;
    displaylist(head);
    return 0;
}