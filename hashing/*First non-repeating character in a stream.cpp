#include <bits/stdc++.h>
using namespace std;

void solve(char arr[],int n)
{
    unordered_map<char,int>mp;
    queue<char>q;
 
    for(int i=0;i<n;i++)
    {
        q.push(arr[i]);
        mp[arr[i]]++;
        while(mp[q.front()]>1 and !q.empty())
        {
            q.pop();
        }
        if(q.empty())
        {
            cout<<"-1 ";
        }
        else
        {
            cout<<q.front()<<" ";
        }
    }
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        // unordered_map<char,int>mp;
        // queue<int>q;
        cin>>n;
        char arr[n];
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        solve(arr,n);
        cout<<"\n";
    }
	//code
	return 0;
}
