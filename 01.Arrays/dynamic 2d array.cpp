#include <iostream>

using namespace std;



int main()
{

	int size;
	cin>>size;
	if(size <1)
	{
		cout<<"Size of the matrix should be positive!"<<endl;
		return 0;
	}

	int **arr = new int*[size];

	for(int i = 0 ; i< size ; i++)
	{
		arr[i] = new int[size];
	}


	for(int i = 0 ; i<size ; i++)
	{

		for(int j = 0 ; j<size ; j++)
		{
			cin>>arr[i][j];
		}
	}






	cout<<"Original Matrix:"<<endl;
	for(int i = 0 ; i<size  ; i++)
	{
		for(int j = 0 ;j< size ;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}


	cout<<"Matrix after 90-degree clockwise rotation:"<<endl;

	for(int j = 0 ; j< size ; j++)
	{
		for(int i= size-1 ; i>= 0 ; i--)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i = 0  ; i< size ;i++)
	{
		delete[] arr[i];
	}


}