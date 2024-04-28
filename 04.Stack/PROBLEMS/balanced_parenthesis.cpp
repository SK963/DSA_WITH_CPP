#include <bits/stdc++.h>
using namespace std;


bool isValidParentheses(string expression)
{  
   
    stack<char> s;
    char x;
 
 
    for (int i = 0; i < expression.length(); i++) 
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') 
        {
         
            s.push(expression[i]);
            continue;
        }
 

        if (s.empty())
        {
            return false;
        }
 
       
        x = s.top();
        s.pop();
       
        
        switch (expression[i]) {
        case ')':
           
            if (x == '{' || x == '[')
            {
                return false;
            }
            break;
 
        case '}':
 
            if (x == '(' || x == '[')
            {
                return false;
            }
            break;
 
        case ']':
           
            if (x == '(' || x == '{')
            {
                return false;
            }
            break;
        }
    }
 

    return (s.empty());
}

int main()
{
    cout<<"enter the expression - ";
    string expr ;
    cin>>expr;

    if (isValidParentheses(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}