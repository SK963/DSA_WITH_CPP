
#include <iostream>

using namespace std;


int stack[100]
int choice,n,top,x,i;



void push()
{
    if(top>=n-1)
    {
        cout<<"\n\tSTACK is over flow";
        
    }
    else
    {
        cout<<" Enter a value to be pushed:";
        cin>>x;
        top++;
        stack[top]=x;
    }
}


void pop()
{
    if(top<=-1)
    {
        cout<<"\n\t Stack is under flow";
    }
    else
    {
        cout<<"\n\t The popped elements is"<<stack[top];
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        cout<<"The elements in STACK:- ";
        for(i=top; i>=0; i--)
            cout<<stack[i]<<" ";
        
        cout<<endl<<"Press Next Choice";
    }
    else
    {
        cout<<"\n The STACK is empty";
    }
   
}


int main()
{
    top=-1;
    cout<<"\n Enter the size of STACK:";
    cin>>n;
    cout<<"\n\t STACK OPERATIONS USING ARRAY";
    cout<<"\n\t--------------------------------";
    cout<<"\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT";
    do
    {
        cout<<"\n Enter the Choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                cout<<"\n\t EXIT POINT ";
                break;
            }
            default:
            {
                cout<<"\n\t Please Enter a Valid Choice(1/2/3/4)";
            }
                
        }
    }
    while(choice!=4);
    return 0;
}
