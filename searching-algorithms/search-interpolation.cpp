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

int interpolationSearch(int *A, int n, int x)
{
    int low = 0;
    int high = n-1;
    int pos = low + (x - A[low])*(high - low) / (A[high] - A[low]);

    while( A[low] <= x && x <= A[high] && low <= high)
    {
        if(x < A[pos])
        {
            high = pos - 1;
            pos = low + (x - A[low])*(high - low) / (A[high] - A[low]);
        }
        else if(x > A[pos])
        {
            low = pos+1;
            pos = low + (x - A[low])*(high - low) / (A[high] - A[low]);
        }
        if(x == A[pos])
        {
            return pos;
        }
    }

    return -1;
}


int main()
{
    //int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; /// uniform array
    int A[] = {1, 3, 3, 14, 15, 26, 27, 38, 49, 50};
    // int A[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int n = sizeof(A)/sizeof(int);
    print(A,n);

    int key;
    cout<<"Enter a key to search: ";
    cin>>key;

    int index = interpolationSearch(A,n,key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;
    return 0;
}

// ref: geeksforgeeks
/* The formula for pos can be derived as follows.

Let's assume that the elements of the array are linearly distributed. 

General equation of line : y = m*x + c.
y is the value in the array and x is its index.

Now putting value of lo,hi and x in the equation
arr[hi] = m*hi+c ----(1)
arr[lo] = m*lo+c ----(2)
x = m*pos + c     ----(3)

m = (arr[hi] - arr[lo] )/ (hi - lo)

subtracting eqxn (2) from (3)
x - arr[lo] = m * (pos - lo)
lo + (x - arr[lo])/m = pos
pos = lo + (x - arr[lo]) *(hi - lo)/(arr[hi] - arr[lo]) */