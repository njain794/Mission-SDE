#include <bits/stdc++.h>
using namespace std;

bool isvalid(int arr[],int mid,int n,int m)
{
    int painters=1;
    int sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum>mid)
        {
            painters++;
            sum=arr[i];
        }
        if(painters>m)
        {
            return false;
        }
    }
    return true;
}
int solve(int arr[],int n,int m)
{
    int mx=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
       mx=max(mx,arr[i]);
       sum+=arr[i];
    }
    
    int start=mx;
    int end=sum;
    int res=-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isvalid(arr,mid,n,m))
        {
            res=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
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
        int m,n,arr[1000];
        cin>>m;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n,m)<<"\n";
    }
	return 0;
}
