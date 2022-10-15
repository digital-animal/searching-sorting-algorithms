#include<iostream>
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

void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void simpleSort(int *A,int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(A[i] < A[j])
            {
                swap(&A[i], &A[j]);
            }
        }
    }
}

int main()
{
    int A[] = {4, 9, 2, 3, 5, 7 ,8, 1, 6, 0};
    int n = sizeof(A) / sizeof(int);

    cout<<"Before sorting: "<<endl;
    print(A,n);

    simpleSort(A,n);

    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}
