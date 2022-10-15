#include<iostream>
#include<algorithm>
#include<cmath>
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

int digitCount(int num)
{
    int count = 0;
    while (num)
    {
        num = num / 10;
        count++;
    }
    return count;
}

void countingSort(int *A, int n, int pos)
{
    int min = *min_element(A, A+n); // O(n)
    if (min < 0)
    {
        // for negative value add-sub
        return;
    }

    int m = 10;
    int B[n] = {0}; // for copying back
    int C[m] = {0}; // for counting

    // O(n)
    for (int i = 0; i < n; i++)
    {
        C[(A[i] / pos) % 10]++; // building frquency array
    }
    
    // O(m)
    for (int i = 1; i < m; i++)
    {
        C[i] = C[i] + C[i-1]; // building cumulative frquency array
    }

    // O(n)
    for (int i = n-1; i >=0; i--)
    {
        B[--C[(A[i] / pos) % 10 ]] = A[i];
    }

    // O(n)
    for (int i = 0; i < n; i++)
    {
        A[i] = B[i];
    }

}

void radixSort(int *A, int n)
{
    int min = *min_element(A, A+n); // O(n)
    int max = *max_element(A, A+n); // O(n)
    if (min < 0)
        return;

    int i = 0;
    int m = digitCount(max);
    int position = 1;
    
    while (max / position)
    {
        countingSort(A,n,position);
        position = position * 10;

        cout<<"# iteration "<< ++i <<endl;
        print(A,n);
    }
}

int main()
{
    int A[] = {432,8,520,90,88,23,11,8,45,677,199};
    int n = sizeof(A) / sizeof(int);

    cout<<"n: " << n <<endl;
    cout<<"Before sorting: "<<endl;
    print(A,n);

    radixSort(A,n);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}


