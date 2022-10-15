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

// merge function
void merge(int *A, int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = 0;

    int *C = new int[high-low+1];

    while(i<=mid && j<=high)
    {
        if(A[i] <= A[j])
            C[k++] = A[i++];
        else
            C[k++] = A[j++];
    }

    // copy if any elements remain in the first part of the list
    while(i <= mid)
    {
        C[k++] = A[i++];
    }

    // copy if any elements remain in the second part of the list
    while(j <= high)
    {
        C[k++] = A[j++];
    }

    k = 0;
    // copying back merged elements
    for(int i=low; i<=high; i++)
    {
        A[i] = C[k++];
    }
}

// mergeSort function
void mergeSort(int *A, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main()
{
    int A[] = {4, 9, 2, 3, 5, 7 ,8, 1, 6, 0};
    int n = sizeof(A) / sizeof(int);

    cout<<"Before sorting: "<<endl;
    print(A,n);

    mergeSort(A, 0, n-1);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}
