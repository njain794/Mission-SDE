#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//insertion sort
/*void sort(int arr[],int n)
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
}*/
//selection sort
/*void sort(int arr[],int n)
{
    int min_idx,j;
    for(int i=0;i<n-1;i++)
    {
        min_idx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
                //swap(arr[i],arr[min_idx]);
            }
            //swap(arr[min_idx],arr[i]);
        }
        swap(arr[i],arr[min_idx]);
    }
}*/
//bubble sort
/*void sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}*/
//quick sort
/*int part(int arr[],int low,int hii)
{
    int pivot=arr[hii];
    int i=low-1;

    for(int j=low;j<=hii-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[hii]);
    return i+1;
}
void sort(int arr[],int i,int j)
{
    if(i<j)
    {
        int pi=part(arr,i,j);
        sort(arr,i,pi-1);
        sort(arr,pi+1,j);
    }
    return;
}*/
//merge sort
/*void merge(int arr[],int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=0;
    int temp[e-s+1];

    while(i<=mid and j<=e)
    {
        if(arr[i]<arr[j])
        {
            temp[k]=arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=arr[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=e)
    {
        temp[k]=arr[j];
        k++;
        j++;
    }

    int h=0;
    for(int g=s;g<=e;g++)
    {
        arr[g]=temp[h];
        h++;
    }

}
void sort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    sort(arr,s,mid);
    sort(arr,mid+1,e);
    merge(arr,s,e);
}*/

int main() {
    int arr[11]={3,6,1,2,7,8,4,3,12,9,5};
    //sort(arr,11);
    sort(arr,0,10);
    for(int i=0;i<11;i++)
    {
        cout<<arr[i]<<" ";
    }
}
