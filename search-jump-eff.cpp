#include<iostream>
#include<cmath>
using namespace std;

//Jump Search
int jumpSearch(int A[],int n,int key)
{
    int blocksize=sqrt(n);

    int start = 0;
    int end = blocksize;
    int index;
    int i = 1;
    while(key >= A[end] && end < n)
    {
        start = end;
        end = end + blocksize;
        if(end > n-1)
            end = n;
    }

    for(int i=start; i<end; i++)
    {
        if(A[i] == key)
        {
            return i;
            break;
        }
    }
    return -1;
}

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

int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,14,17,19,21,23,27,29,30};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"Array Size: "<<n<<endl;
    cout<<"Given Array: "<<endl;
    print(A,n);

    int key;
    cout<<"Enter a key to search: ";
    cin>>key;

    int position = jumpSearch(A,n,key);

    if(position != -1)
    {
        cout<< key <<" found at index "<< position <<endl;
    }
    else
    {
        cout<< key <<" not found."<<endl;
    }

    return 0;

}
