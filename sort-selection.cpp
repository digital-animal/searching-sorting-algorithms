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

void swap(int &x,int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// strategy is 'select' the min element in each sub array and place it before it
void selectionSort(int *A,int n)
{
    int minima;
    for(int i=0; i<n; i++)
    {
        minima = A[i];
        for(int j=i+1; j<n; j++)
        {
            if(A[j] < minima)
            {
                minima = A[j];
                swap(A[i], A[j]);
            }
        }
    }
}

// strategy is 'select' the min element in each sub array and place it before it
void selectionSort1(int *A,int n)
{
    int min_index;
    for(int i=0; i<n; i++)
    {
        min_index = i;
        for(int j=i+1; j<n; j++)
        {
            if(A[j] < A[min_index])
            {
                min_index = j;
            }
        }
        if (i != min_index)
        {
            swap(A[i], A[min_index]);
        }
    }
}

int main()
{
    int A[] = {4, 9, 2, 3, 5, 7 ,8, 1, 6, 0};
    int n = sizeof(A) / sizeof(int);

    cout<<"Before sorting: "<<endl;
    print(A,n);

    // selectionSort(A,n);
    selectionSort1(A,n);

    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}

