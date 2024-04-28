
#include <iostream>
#include <string>

using namespace std;


struct node
{
int  data;
node* link;
};

void insertatend(node** head , int data)
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
}

int main() 
{
    int size ;
    int data;
    node* head = NULL;
    cout<<"enter the size for linked list :- ";
    cin>>size;
    
    for(int i = 1 ; i <= size ; i++)
        {
            cin>>data;
            insertatend(&head, data);
        }

    
    cout<<"linked list:- ";
    displaylist(head);
    
}