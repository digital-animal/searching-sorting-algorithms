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

int fibo(int n)
{
    if(n==0 || n==1)
    {
        return n;
    }

    return fibo(n-1) + fibo(n-2);
}

int fibonacciSearch(int *A,int n,int x)
{
    // pass

    return -1;
}

int main()
{
    int A[] = {0,1,2,3,5,7,9,10,21,27,31,33,34,37,44,51,52,59,61,69,71,72,73,79,90,100,130,140,160,170,176,178,189,192};
    int n = sizeof(A) / sizeof(int);
    cout<<"n = "<<n<<endl;
    print(A,n);

    int key;
    cout<<"Enter a key to search: ";
    cin>>key;
    
    int index = fibonacciSearch(A,n,key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;

    return 0;

}
