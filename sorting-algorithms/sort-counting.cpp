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


void countingSort(int *A, int n)
{
    int min = *min_element(A, A+n); // O(n)
    int max = *max_element(A, A+n); // O(n)

    if (min < 0)
    {
        // for negative value add-sub
        return;
    }

    int m = max + 1;
    int B[n] = {0}; // for copying back
    int C[m] = {0}; // for counting

    // O(n)
    for (int i = 0; i < n; i++)
    {
        C[A[i]]++; // building frquency array
    }
    
    // O(m)
    for (int i = 1; i < m; i++)
    {
        C[i] = C[i] + C[i-1]; // building cumulative frquency array
    }

    // O(n)
    for (int i = n-1; i >=0; i--)
    {
        // B[--C[A[i]] ] = A[i];

        int val = A[i];
        int index = --C[A[i]];
        B[index] = val;
    }

    // O(n)
    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }

}

int main()
{
    int A[] = {1,0,1,1,2,1,2,3,4,5,0,3,4,5,1,0,3,2,3,2,2,1,0,3};
    int n = sizeof(A) / sizeof(int);

    cout<<"n: " << n <<endl;
    cout<<"Before sorting: "<<endl;
    print(A,n);

    countingSort(A,n);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}


