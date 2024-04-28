#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows) ;
        for(int i = 0 ; i< numRows ; i++)
        {   
			pascal[i].resize(i+1);
            for(int j = 0 ; j <= i ; j++)
            {
				
                if(i >= 1 && (j != 0 && j != i))
                    pascal[i][j] =  pascal[i-1][j-1] + pascal[i-1][j];
                else 
                    pascal[i][j] = 1;
            }
        }
        return pascal;

    }
};

int main()
{
	

	
	int n;
	cin>>n;
	
		
	Solution obj;   
	vector<vector<int>>result = obj.generate(n);
	

	for(int i = 0 ; i< result.size() ; i++)
		{
			cout<<"[";
			for(int j = 0 ; j< result[i].size() ; j++)
				{
					cout<<result[i][j]<<" ";
				}
			cout<<"]"<<endl;
		}

			
		
}