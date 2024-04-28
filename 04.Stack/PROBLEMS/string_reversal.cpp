#include <iostream>
using namespace std;

// Define a structure for a stacknode in the linked list
struct stacknode 
{
    char data;
    stacknode* link;
};

class Stack 
{
private:
    stacknode* top; // Pointer to the top of the stack

public:
    Stack() {
        top = NULL; // Initialize the stack as empty
    }

    // Function to push an element onto the stack
    void push(char value) {
        stacknode* newstacknode = new stacknode();
        newstacknode->data = value;
        newstacknode->link = top;
        top = newstacknode;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow: The stack is empty." <<endl;
            return;
        }
        
        stacknode* temp = top;
        top = top->link;
        delete temp;
    }

    void display()
    {
        stacknode *ptr = top;
        if(ptr ==  NULL)
        {
            cout<<"The stack is empty."<<endl;
            return;
        }
        
        while(ptr != NULL)
            {
                cout<<ptr->data<<"";
                ptr = ptr->link;
            }
        
        cout<<endl;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Function to return the top element of the stack without popping it
    int Top() {
        if (isEmpty()) {
            cout << "Stack is empty." <<endl;
            return -1; // Return a sentinel value or throw an exception as needed
        }
        return top->data;
    }
};



int main() 
{
    Stack revstring;

    string str;

    cout<<"Enter the string:- ";
    getline(cin,str);

    char *ptr = &str[0];


    for(int i= 0 ; i< str.length(); i++)
        {
            revstring.push(*ptr);
            ptr++;
        }


    cout<<"the reversed string :- ";
    revstring.display();
    return 0;
}
