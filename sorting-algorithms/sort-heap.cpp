#include<iostream>
#include<algorithm>
using namespace std;

void print(int *A, int n)
{
    cout<< "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
            cout<< A[i] << "";
        else
            cout<< A[i] << ",";
    }
    cout<< "]" <<endl;
}

void heapSort(int *A,int n)
{
    // pass
    
}

int main()
{
    // int A[] = {4, 9, 2};
    // int A[] = {4, 9, 2, 3, 5};
    int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0};

    int n = sizeof(A) / sizeof(int);

    cout<<"Before sorting: "<<endl;
    print(A,n);

    heapSort(A,n);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}