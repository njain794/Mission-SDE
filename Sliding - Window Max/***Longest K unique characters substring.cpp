#include <bits/stdc++.h>
using namespace std;

int solve(string s,int k)
{
    int n=s.size();
    int i=0,j=0;
    unordered_map<char,int>mp;
    int res=INT_MIN;
    while(j<n)
    {
        mp[s[j]]++;
        if(mp.size()<k)
        {
            j++;
        }
        else if(mp.size()==k)
        {
            res=max(res,j-i+1);
            j++;
        }
        else
        {
            while(mp.size()>k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
                
            }
            j++;
        }
    }
    if(res==INT_MIN)
    {
        return -1;
    }
    return res;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int k;
        cin>>s;
        cin>>k;
        cout<<solve(s,k)<<"\n";
    }
	//code
	return 0;
}
