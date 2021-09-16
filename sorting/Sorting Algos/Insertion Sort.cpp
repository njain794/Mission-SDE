#include <iostream>
using namespace std;

void sort(int arr[],int n)
{
    //int n=*(&arr+1)-arr;//sizeof(arr)/sizeof(arr[0]);
    int val,j;
    for(int i=1;i<n;i++)
    {
        val=arr[i];
        j=i-1;
        while(j>=0 and arr[j]>val)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=val;
    }
}

int main() {
    int arr[11]={3,6,1,2,7,8,4,3,12,9,5};
    sort(arr,11);
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<" ";
    }
}
