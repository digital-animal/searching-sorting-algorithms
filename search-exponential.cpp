#include<iostream>
using namespace std;

void print(int *A, int n)
{
    cout<< "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            cout<< A[i] << "";
        }
        else
        {
            cout<< A[i] << ",";
        }
    }
    cout<< "]" <<endl;
}

int binarySearch(int *A, int low, int high, int key)
{
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

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

// exponential search
int exponentialSearch(int *A,int n,int x)
{
    int i = 0;
    if(A[i]==x)
    {
        return i;
    }
    
    i++;
    while(i <n && A[i] <= x)
    {
        if(A[i] == x)
        {
            return i;
        }
        i = i*2;
    }
    return binarySearch(A, i/2, n-1, x);
}


int main()
{
    //int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; /// uniform array
    //int A[] = {1, 3, 3, 14, 15, 26, 27, 38, 49, 50};
    int A[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int n = sizeof(A)/sizeof(int);
    print(A,n);

    int key;
    cout<<"Enter a key to search: ";
    cin>>key;

    int index = exponentialSearch(A,n,key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;
    return 0;
}

