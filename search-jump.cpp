#include<iostream>
#include<cmath>
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

int linearSearch(int *A, int l, int r, int key)
{
    for(int i=l; i<=r; i++)
    {
        if(A[i] == key)
        {
            return i;
        }
    }
    return -1;
}   

int jumpSearch(int *A, int n, int key)
{
    int m = sqrt(n);
    int start = 0;
    int end = m;
    while(key >= A[end] && end < n)
    {
        start = end;
        end = end + m;
        if(end >= n)
        {
            end=n-1;
            break;
        }
    }
    return linearSearch(A, start, end, key);

}

int main()
{
    //int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int A[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int n=sizeof(A)/sizeof(int);
    print(A,n);
    //cout<<n<<endl;
    int key;
    cout<<"Enter a key to search: ";
    cin>>key;

    int index = jumpSearch(A,n,key);
    if(index != -1)
        cout<< key <<" found at index "<< index <<endl;
    else 
        cout<< key <<" not found in the array"<<endl;

    return 0;
}


/// PSEUDOCODE

//Begin
//   blockSize := √size
//   start := 0
//   end := blockSize
//   while array[end] <= key AND end < size do
//      start := end
//      end := end + blockSize
//      if end > size – 1 then
//         end := size
//   done
//   for i := start to end -1 do
//      if array[i] = key then
//         return i
//   done
//   return invalid location
//End

