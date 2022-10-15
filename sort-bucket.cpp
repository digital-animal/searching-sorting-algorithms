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

void bucketSort(int *A, int n)
{
    // pass
}

int main()
{
    int A[] = {1,0,1,1,2,1,2,3,4,5,0,3,4,5,1,0,3,2,3,2,2,1,0,3};
    int n = sizeof(A) / sizeof(int);

    cout<<"n: " << n <<endl;
    cout<<"Before sorting: "<<endl;
    print(A,n);

    bucketSort(A,n);
    
    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}


