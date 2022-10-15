#include<iostream>
using namespace std;

int binarySearch(int *A, int low, int high, int key)
{
    int mid=(low + high) >> 1; // right shift i.e. division by 2
    if(low <= high)
    {
        if(key < A[mid])
        {
            return binarySearch(A, low, mid-1, key);
        }
        else if(key > A[mid])
        {
            return binarySearch(A, mid+1, high, key);
        }
        else if(key == A[mid])
        {
            return mid;
        }
    }

    return  -1;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(A) / sizeof(int);
    int key;
    cout<<"Enter a key to search: ";
    cin>>key;

    int index = binarySearch(A, 0, n-1, key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;

    return 0;
}


