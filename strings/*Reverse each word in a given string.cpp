#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='.')
        {
            st.push(s[i]);
        }
        else if(s[i]=='.')
        {
            while(!st.empty())
            {
                cout<<st.top();
                st.pop();
            }
            cout<<".";
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
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
