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

void swap(int &x, int &y)
{
    x =  x ^ y;
    y =  x ^ y;
    x =  x ^ y;
}

void shellSort(int *A,int n)
{
    int gap = n/2;
    while (gap)
    {
        for (int i = 0; i < n; i++)
        {
            int j = i + gap;
            if (j< n && A[i] > A[j])
            {
                swap(A[i], A[j]);
                
                int k = i - gap;
                if (k >= 0 && A[i] < A[k])
                {
                    swap(A[i], A[k]);
                }
            }
        }
        gap = gap / 2;
    }
}

int main()
{
    int A[] = {4, 9, 2, 3, 5, 7 ,8, 1, 6, 0, -123, 371};
    int n = sizeof(A) / sizeof(int);

    cout<<"Before sorting: "<<endl;
    print(A,n);

    shellSort(A,n);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}