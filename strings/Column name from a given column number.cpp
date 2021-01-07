#include <bits/stdc++.h>
using namespace std;

void solve(int n)
{
    string temp;
    char ch='A';
    for(int i=0;i<26;i++)
    {
        temp.push_back(ch++);   
    }
    string ans;
    while(n>0)
    {
        int rem=n%26;
        if(rem==0)
        {
            ans.push_back('Z');
            n=(n/26)-1;
        }
        else
        {
            ans.push_back(temp[rem-1]);
            n=n/26;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        solve(n);
        cout<<"\n";
    }
	//code
	return 0;
}
