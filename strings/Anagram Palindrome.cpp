#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    unordered_map<char,int>mp;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        mp[s[i]]++;
    }
    int count =0;
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        int d=it->second;
        if(d%2!=0)
        {
            count++;
        }
    }
    if(count>1)
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
}

int main() 
{
    //unordered_map<char,int>mp;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        solve(s);
        cout<<"\n";
    }
	//code
	return 0;
}
