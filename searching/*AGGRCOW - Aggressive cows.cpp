#include <bits/stdc++.h>
using namespace std;

bool canplace(int arr[],int n,int m,int mid)
{
    int place=arr[0];
    int cows=1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]-place>=mid)
        {
            if(cows==m)
            {
                return true;
            }
            place=arr[i];
            cows++;
        }
        if(cows==m)
        {
            return true;
        }
    }
    return false;
}

int solve(int arr[],int n,int m)
{
    sort(arr,arr+n);

    int start=1;
    int end=n-1;
    int res=0;

    while(start<=end)
    {
        int mid=(start+end)/2;
        if(canplace(arr,n,m,mid))
        {
            res=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return res;
}

int main() 
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,m,arr[n];
       cin>>n;
       cin>>m;

       for(int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       cout<<solve(arr,n,m)<<"\n";
   }
}
