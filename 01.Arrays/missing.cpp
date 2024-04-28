#include <bits/stdc++.h>
using namespace std;




class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        int m_num  = 0;
        for(int i = 1 ; i <= n; i++)
        {
            bool status = true;  //let the number is absent in the array
            int j = 0;
            for(j = 0 ; j< n-1 ; j++)
            {
                if(array[j] == i){ // if matches then 
                    status = false; // it the assumption is false
                    break;  // break the inner loop
                }
                
            }
            
           if(status)  // if not found then the missing number is
           {
               m_num = i;
               break;
               
           }
            
            
        }
        
        return m_num;
        
        
    }
};


int main()
{
	

	
	int n;
	cin>>n;
	vector<int> array(n-1);
	for(int i = 0 ; i < n-1 ; i++)
		{
			cin>>array[i];
		}
		
	Solution obj;
	int missingnum = obj.missingNumber(array,n);
	cout<<missingnum<<endl;
		
			
			
		
}