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

/////////////// OR /////////////////

class Solution {
	public:
		string FirstNonRepeating(string A)
		{
		    int hash[26]={0};
		    string ans;
		    queue<char>q;
		    for(int i=0;i<A.size();i++)
		    {
		        hash[A[i]-'a']++;
		        q.push(A[i]);
		        while(!q.empty() and hash[q.front()-'a']>1)
		        {
		            q.pop();
		        }
		        if(q.empty())
		        {
		            ans+='#';
		        }
		        else
		        {
		            ans+=q.front();
		        }
		    }
		    return ans;
		    // Code here
		}	
};
