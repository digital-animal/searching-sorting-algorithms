#include<iostream>
using namespace std;

void print(int *A, int n)
{
    cout<< "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            cout<< A[i] << "";
        }
        else
        {
            cout<< A[i] << ",";
        }
    }
    cout<< "]" <<endl;
}

int linearSearch(int *A,int n,int key)
{
    for(int i=0; i<n; i++)
    {
        if(A[i] == key)
        {
            return i;
        }
    }
    return -1;
}   

int main()
{
    int A[] = {4, 9, 2, 3, 5, 7, 8, 1, 6, 0};
    int n = sizeof(A) / sizeof(int);
    print(A,n);
    int key;
    cout<<"Enter a key to search: ";
    cin>>key;
    
    int index = linearSearch(A,n,key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;

    return 0;
}
