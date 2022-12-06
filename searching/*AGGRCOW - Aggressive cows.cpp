bool canPlace(vector<int> &arr,int n,int mid,int k)
    {
        int cows=1;
        int curr=arr[0];
        for(int i=1;i<n;i++)
        {
            if(abs(arr[i]-curr)>=mid)
            {
                curr=arr[i];
                cows++;
            }
        }
        return cows>=k;
    }

    int solve(int n, int k, vector<int> &arr) 
    {
        sort(arr.begin(),arr.end());
        
        int start = 1;
        int end = arr[n-1]-arr[0];
        
        int ans=1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            
            if(canPlace(arr,n,mid,k))
            {
                ans=mid;
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
        }
        return ans;
    }
******************************************************************
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
