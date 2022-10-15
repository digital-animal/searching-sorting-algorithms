#include<iostream>
using namespace std;

int ternarySearch(int *A, int n, int x)
{
    int left = 0;
    int right = n - 1;
    while(left <= right)
    {
        int mid_first = left + (right-left)/3;
        int mid_second = mid_first + (right-left)/3;
        
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
            right = mid_first - 1;
        }
        else if(x > A[mid_second])
        {
            left = mid_second + 1;
        }
        else if(x > A[mid_first] && x < A[mid_second])
        {
            left = mid_first + 1;
            right = mid_second - 1;
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

    int index = ternarySearch(A, n, key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;

    return 0;
}
