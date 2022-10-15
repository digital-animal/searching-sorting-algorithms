#include<iostream>
using namespace std;

int ternarySearch(int *A, int left, int right, int x)
{
    if(right-left >= 0)
    {
        int mid_first = left+(right-left)/3;
        int mid_second = mid_first+(right-left)/3;
        
        if(x == A[mid_first])
        {
            return mid_first;
        }
        else if(x == A[mid_second])
        {
            return mid_second;
        }
        else if(x < A[mid_first])
        {
            return ternarySearch(A,left,mid_first-1,x);
        }
        else if(x > A[mid_second])
        {
            return ternarySearch(A,mid_second+1,right,x);
        }
        else if(x > A[mid_first] && x < A[mid_second])
        {
            return ternarySearch(A,mid_first+1,mid_second-1,x);
        }
    }

    return -1;
}

int main()
{
    //int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int A[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int n = sizeof(A)/sizeof(A[0]);
    int key;
    cout<<"Enter a key to search: ";
    cin>>key;

    int index = ternarySearch(A,0,n-1,key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;

    return 0;
}
