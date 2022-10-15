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

bool sorted(int *A, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        if (A[i] > A[i+1])
        {
            return false;
        }
    }
    return true;
}

void bogoSort(int *A,int n)
{
    while (!sorted(A,n))
    {
        // print(A,n);
        // cout<<"isSorted = "<< (sorted(A, n)? "true": "false") << endl;

        random_shuffle(A, A+n);
    }
    
    
}

int main()
{
    // int A[] = {4, 9, 2};
    // int A[] = {4, 9, 2, 3, 5};
    // int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0};
    int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0, 11};
    // int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0, 11, 17};
    // int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0, 11, 17, 13, 19};
    // int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0, 11, 17, 13, 19, 29};
    // int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0, 11, 17, 13, 19, 29, 23};
    int n = sizeof(A) / sizeof(int);

    cout<<"Before sorting: "<<endl;
    print(A,n);

    bogoSort(A,n);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}