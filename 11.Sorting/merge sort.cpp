// Merge Sort implementaion
#include <iostream>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[start..mid]
// Second subarray is arr[mid+1..end]

void merge(int array[], int const left, int const mid,int const right)
{
    //step 1 - finding the size of the arrays 
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    //step 2 - making temp array 
    //-------------------------------------------------------
    // Create temp dynamically memory allocated arrays
    // auto *leftArray = new int[subArrayOne];  
    // auto *rightArray = new int[subArrayTwo];
    //-------------------------------------------------------
    //or - 
    int leftArray[subArrayOne];
    int rightArray[subArrayTwo];

    // step 3 -  Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int arr1index = 0, arr2index = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (arr1index < subArrayOne && arr2index < subArrayTwo) 
    {
        if (leftArray[arr1index] <= rightArray[arr2index]) 
        {
            array[indexOfMergedArray] = leftArray[arr1index];
            arr1index++;
        }
        else 
        {
            array[indexOfMergedArray] = rightArray[arr2index];
            arr2index++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of left[], and right[] if there are any
    while (arr1index < subArrayOne) 
    {
        array[indexOfMergedArray] = leftArray[arr1index];
        arr1index++;
        indexOfMergedArray++;
    }

    while (arr2index < subArrayTwo) 
    {
        array[indexOfMergedArray] = rightArray[arr2index];
        arr2index++;
        indexOfMergedArray++;
    }

    
    // delete[] leftArray;
    // delete[] rightArray;
}

// start is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const start, int const end)  
{
    if (start >= end) //(==) gives the same result
        return;

    int mid = start + (end - start) / 2;
    mergeSort(array, start, mid);  //divide
    mergeSort(array, mid + 1, end); //divide
    merge(array, start, mid, end); //conquer 
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}

