#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> subarray;
void SubArrays(vector<int> arr, int start, int end)
{
    vector<int> temp;

    if (end == arr.size()) // base condition
        return;

    else if (start > end)  //even startsindex is greater i will take from the first index.
        SubArrays(arr, 0, end + 1);

    else 
        {
       
            for (int i = start; i <= end; i++)
            temp.push_back(arr[i]);


            subarray.push_back(temp); // storing each subarray
            temp.clear();  // clearing the temp vector

            SubArrays(arr, start + 1, end);
        }
        return;
}
    
int maxSubArray(vector<int>& nums)
    {
        SubArrays(nums , 0 , 0);
        int sum = 0;
        int max = 0;

        for(int i = 0 ; i< subarray.size() ; i++)
        {
            sum = 0;
            for(int j = 0 ; j < subarray[i].size() ; j++)
            {
                sum += subarray[i][j];
            }
            
            cout<<"[";
            for(auto x: subarray[i])
            {
                cout<<x<<" ";
            }cout<<"]"<<endl;

            if(sum > max)
            max = sum;
        }
        return max;

}


int main()
{
    vector<int>array = {1,2,-4,3,-6, 8};
    int maxsubarraysum = maxSubArray(array);
    cout<<endl;
    cout<<maxsubarraysum<<endl;
}