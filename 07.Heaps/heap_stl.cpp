#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    vector<int> v;
    int i;
    while(cin>>i) 
        {
            v.push_back(i);
        }
    make_heap(v.begin(), v.end() , greater<int>());

    for(auto q : v)
        {
            cout<<q<<" ";
        }cout<<endl;
}