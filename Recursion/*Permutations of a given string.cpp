#include <bits/stdc++.h>
using namespace std;

void permute(string s,string ans,vector<string> &v)
{
    if(s.length()==0)
    {
        v.push_back(ans);
        //cout<<ans<<" ";
        return;
    }
    
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        permute(ros,ans+ch,v);
    }
}

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        string ans="";
        vector<string>v;
        cin>>s;
        permute(s,ans,v);
        sort(v.begin(),v.end());
        for(auto x:v)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
	//code
	return 0;
}
