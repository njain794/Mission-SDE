#include <bits/stdc++.h>
using namespace std;

pair<int,int> solve(int n,int m,int arr1[],int arr2[],int k)
{
    int l=0,r=m-1;
    int diff=INT_MAX;
    pair<int,int>p;
    while(l<n and r>=0)
    {
        if(abs(arr1[l]+arr2[r]-k)<diff)
        {
            diff=abs(arr1[l]+arr2[r]-k);
            p.first=arr1[l];
            p.second=arr2[r];
        }
        if(arr1[l]+arr2[r]<k)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return p;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,arr1[1000],arr2[1000],k,m;
        cin>>n;
        cin>>m;
        for(int i=0;i<n;i++)
        {
            cin>>arr1[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>arr2[i];
        }
        cin>>k;
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        pair<int,int>p=solve(n,m,arr1,arr2,k);
        cout<<p.first<<" "<<p.second<<"\n";
    }
	//code
	return 0;
}
