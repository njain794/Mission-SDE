#include <bits/stdc++.h>
using namespace std;

int solve(string s)
{
    map<pair<int,int>,int>mp;
    mp[make_pair(0,0)]=1;
    int res=0;
    int c0=0,c1=0,c2=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]-'0'==1)
        {
            c1++;
        }
        else if(s[i]-'0'==0)
        {
            c0++;
        }
        else
        {
            c2++;
        }
        
        pair<int,int>temp=make_pair(c1-c0,c2-c1);
        res=res+mp[temp];
        mp[temp]++;
    }
    return res;
}
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string st;
        cin>>st;
        cout<<solve(st)<<"\n";
    }
	//code
	return 0;
}
