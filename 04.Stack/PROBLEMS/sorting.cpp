#include <iostream>

using namespace std;

struct node 
{
   int data;
   struct node *link;
};

struct node* top = NULL;

void push(int val) 
{
   struct node* newnode = new node;
   newnode->data = val;
   newnode->link = top;
   top = newnode;
    cout<<"The pushed item is "<<val<<endl;
}


void pop() 
{
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else 
   {
      cout<<"The popped element is "<< top->data <<endl;
      top = top->link;
   }
}

void display() 
{
   struct node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else 
   {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) 
      {
         cout<< ptr->data <<" ";
         ptr = ptr->link;
      }
   }
   cout<<endl;
}

void sort()
{
    node *curr = top;
    node *next;
    
    while(curr !=  NULL)
        {
            
            if(curr->data > curr->link->data)
            {
                int temp1 = curr->data;
                int temp2 = curr->link->data;
                pop();
                pop();
                
                push(temp1);
                push(temp2);
            }
            curr = curr->link;
        }
}

int main()
{
    int size;
    cout<<"Enter the size:- ";
    cin>>size;

    int data;

    for(int i = 0; i< size ; i++)
        {
            cin>>data;
            push(data);
        }

    cout<<"the original stack :- ";
    display();
    sort();
    cout<<endl<<"the sorted stack:- ";
    display();
}