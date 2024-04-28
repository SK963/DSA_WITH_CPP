#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		

        vector<int> row;
		vector<int> col;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    row.push_back(i);
                    col.push_back(j);
                    
                }
            }
           
        }

		

		while(row.size()!=0 && col.size() != 0)
		{
			
			int rno  =  row.back();
			int cno = col.back(); 

		
		
	        for (int i = 0; i < matrix.size(); i++) {
	            for (int j = 0; j < matrix[i].size() ; j++)
	            {
	                if(rno == i || cno == j)
	                {
	                    matrix[i][j] = 0;
	                }
	            }
	        }
			row.pop_back();
			col.pop_back();
			
	    }
	}
};


int main()
{
	

	
	int n;
	vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
	
		
	Solution obj;
	obj.setZeroes(matrix);


	for(int i = 0 ; i< matrix.size() ; i++)
		{
			for(int j = 0 ; j < matrix[i].size() ; j++)
				{
					cout<<matrix[i][j]<<" ";
				}
			cout<<endl;
		}
	
		
			
			
		
}