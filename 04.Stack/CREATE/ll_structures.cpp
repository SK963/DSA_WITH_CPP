#include <iostream>
using namespace std;

struct Stacknode 
{
	int data;
	Stacknode* link;
};


void push(Stacknode** top, int data)
{
    Stacknode* new_node = new Stacknode();
	new_node->data = data;
	new_node->link = *top;
	*top = new_node;
	// cout << data << " pushed to stack\n";
}


void pop(Stacknode** top)
{
	if (top == NULL)
    {
        cout<<"the stack is empty"<<endl;
        return ;
    }
    
    int popped = (*top)->data;
	Stacknode *temp = (*top);
	*top = (*top)->link;
    
	free(temp);
    // cout<<"item deleted :- "<<popped;
    
}



void display(Stacknode * top)
{
    Stacknode *ptr = top;
    if(ptr ==  NULL)
        return;
    while(ptr != NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->link;
        }
    cout<<endl;
}



void Top(Stacknode *top)
{
    if(top ==  NULL)
    {
        cout<<"The stack is empty";
        return;
    }
    else
    {
        cout<<"the tos data is: "<<top->data<<endl;
    }
}




int isEmpty(Stacknode* top)
{
	return !top;
}


int main()
{
    Stacknode* top = NULL;

    
    int size;
    cout<<"Enter the size of the stack:- ";
    cin>>size;

    int data;
    for(int  i = 0 ; i< size ; i++)
        {
            cout<<"enter the tos item:- ";
            cin>>data;
            push(&top ,data);
        }
    


    cout<<"the original stack:- ";
    display(top);

    pop(&top);

    cout<<"After detleting the tos:- ";
    display(top);
    Top(top);
    
	return 0;
}