#include <bits/stdc++.h>
using namespace std;

void solve2(int start,int n,string &s,set<string>&st)
{
    if(start==n)
    {
        st.insert(s);
        return;
    }
    
    for(int i=start;i<n;i++)
    {
        swap(s[start],s[i]);
        solve2(start+1,n,s,st);
        swap(s[start],s[i]);
    }
    return;
}

void solve(string s)
{
    if(s.size()==0)
    {
        return;
    }
    set<string>st;
    int n=s.size();
    solve2(0,n,s,st);
    for(auto x:st)
    {
        cout<<x<<" ";
    }
}

int main() 
{
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
