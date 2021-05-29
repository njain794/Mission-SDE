#include <bits/stdc++.h>
using namespace std;

bool solve(int n,int arr[])
{
    stack<int>s;
    int root = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<root)
        {
            return false;
        }
        while(!s.empty() and arr[i]>s.top())
        {
            root=s.top();
            s.pop();
        }
        s.push(arr[i]);
    }
    return true;
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,arr[1000];
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(solve(n,arr))
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
        cout<<"\n";
    }
	//code
	return 0;
}
