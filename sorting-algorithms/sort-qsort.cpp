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

// function for swapping
void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

// Hoare partition function
int HoarePartition(int *A, int low, int high)
{
    int pivot = A[low+(high-low)/2];
    int i = low-1;
    int j = high+1;

    while(i < j)
    {
        while(A[++i] < pivot);
        while(A[--j] > pivot);

        if (i < j) swap(A[i], A[j]);
    }
    return j;
}

// quickSort function recursive
void quickSort(int *A, int low, int high)
{
    int p = HoarePartition(A, low, high);
    if(low >= high) return;

    quickSort(A, low, p);
    quickSort(A, p+1, high);

}

int main()
{
    int A[] = {4, 9, 2, 3, 5, 7 ,8, 1, 6, 0};
    int n = sizeof(A) / sizeof(int);

    cout<<"Before sorting: "<<endl;
    print(A,n);

    quickSort(A,0, n-1);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}
