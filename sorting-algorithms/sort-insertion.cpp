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

void insertionSort(int *A,int n)
{
    // two parts: sorted array | unsorted array
    // assuming 1st element A[0] to be in sorted part
    for(int i=1; i<n; i++)
    {
        int current_element = A[i];
        int j = i-1;

        while(j>=0 && A[j] > current_element)
        {
            A[j+1] = A[j]; // shift A[j] right by 1 pos
            j = j - 1;
        }
        A[j+1] = current_element;
    }
}

int main()
{
    int A[] = {4, 9, 2, 3, 5, 7 ,8, 1, 6, 0};
    int n = sizeof(A) / sizeof(int);

    cout<<"Before sorting: "<<endl;
    print(A,n);

    insertionSort(A,n);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}


