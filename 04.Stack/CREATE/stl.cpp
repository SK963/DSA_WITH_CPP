#include <iostream>
#include <stack>
using namespace std;

int main() 
{
   
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    
    if (myStack.empty()) 
    {
        cout << "Stack is empty.\n";
    } 
    else 
    {
        cout << "Stack is not empty.\n";
    }

    // Get the size of the stack
    cout << "Size of the stack: " << myStack.size() << "\n";

    // Access the top element without popping it
    cout << "Top element: " << myStack.top() << "\n";

    // Pop elements from the stack
    myStack.pop();

    // Print elements after popping
    cout << "Elements after popping:\n";
    while (!myStack.empty()) 
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << "\n";

    return 0;
}
