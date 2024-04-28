#include <bits/stdc++.h>
using namespace std;




class Solution{
  public:
    int missingNumber(vector<int>& array, int n) {
        int m_num  = 0;

		vector<int> v(n,0);

		
		
		
        for(int i = 0 ; i < n -1; i++)
        {
			v[array[i]-1]  = array[i];
        }

		for(int i = 0 ; i < n; i++)
			{
				if(v[i] == 0)
					m_num = i+1;
				
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