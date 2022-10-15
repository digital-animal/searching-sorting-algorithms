#include<iostream>
#include<vector>
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

void stalinSort1(int *A,int n)
{
    vector<int> nums;
    vector<int> gulag;
    nums.push_back(A[0]);

    for (int i = 1; i < n; i++)
    {
        int temp = nums.back();
        if (A[i] > temp)
        {
            nums.push_back(A[i]);
        }
        else 
        {
            gulag.push_back(A[i]);
        }
    }
    
    int m = nums.size();
    for (int i = 0; i <n; i++)
    {
        if (i < m)
        {
            A[i] = nums[i];
        }
        else 
        {
            A[i] = -1;
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
    stalinSort1(A,n);

    cout<<"After sorting: "<<endl;
    print(A,n);

    return 0;
}

