#include<iostream>
using namespace std;

int binarySearch(int *A, int n, int key)
{
    int low = 0;
    int high = n-1;
    int mid;
    while(low <= high)
    {
        mid = low + (high - low) / 2;

        if(key < A[mid])
        {
            high = mid - 1;
        }
        else if(key > A[mid])
        {
            low = mid + 1;
        }
        else if(key == A[mid])
        {
            return mid;
        }
    }

    return -1;
}


int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=sizeof(A)/sizeof(int);
    int key;
    cout<<"Enter a key to search: ";
    cin>>key;

    int index = binarySearch(A,n,key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;

    return 0;
}

