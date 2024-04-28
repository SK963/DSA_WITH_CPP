#include <iostream>

using namespace std;
class node
{
    public:
    char data;
    node *link;
    node(char data):data(data) , link(nullptr){}

};

class stack
{
    public:
    node* top;

    stack()
    {
        top = nullptr;
    }


    void push(char data)
    {
        node *new_node = new node(data);
        if(top == nullptr)
        {
            top = new_node;
        }
        else 
        {
            new_node->link = top;
            top = new_node;
        }

    }

    void pop()
    {
        if(top == nullptr)
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        node *temp = top;
        top = top->link;
        delete temp;
    }

    bool isempty()
    {
        if(top == nullptr)
        {
            return true;
        }
        else 
            return false;
    }

    char peek()
    {
        return top->data;
    }

    void print()
    {
        node *ptr = top;
       while(!isempty())
           {
               cout<<peek()<<" ";
               // pop();
               top=top->link;
           }
        cout<<endl;

        top = ptr;
    }

};




int main()
{
    stack s1;
    string s;
    cout<<"enter the string :- ";
    getline(cin, s);

    char *ptr = &s[0];
    for(int i = 0 ; i< s.length(); i++)
        {
            // cout<<*ptr;
            char temp = *ptr;
            s1.push(temp);
            ptr++;
        }
    s1.print();



}

