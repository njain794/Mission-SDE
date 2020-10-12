// { Driver Code Starts
#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000

pair<int,int> findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    rangee = findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

// } Driver Code Ends


// you are required to complete this function 
// function should print the required range
#include<bits/stdc++.h>
pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{
    priority_queue<pair<int,<pair<int,int>>>,vector<pair<int,<pair<int,int>>>,greater<int,<pair<int,int>>>>minh;
    int i=0;
    int mx=INT_MIN;
    while(i<n)
    {
        mx=max(arr[i][0],mx);
        minh.push({arr[i][0],{i,0}});
    }
    int diff=mx-minh.top().first;
    pair<int,int>p;
    p.first=minh.top().first;
    p.second=mx;
    int tempdiff=0;
    while(!minh.empty())
    {
        pair<int,<pair<int,int>>>curr=minh.top();
        minh.pop();
        int d=curr.second.second + 1;
        if(d<n)
        {
            int r=curr.second.first;
            int c=d;
            int val=arr[r][c];
            mx=max(mx,val);
            minh.push({val,{r,c}});
            
            tempdiff=max-minh.top.first;
            if(tempdiff<diff)
            {
                diff=tempdiff;
                p.first=minh.top().first;
                p.second=mx;
            }
        }
        else
        {
            break;
        }
        
    }
    return p;
      //code here
}
