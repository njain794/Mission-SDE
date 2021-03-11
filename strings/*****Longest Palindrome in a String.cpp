#include <iostream>
using namespace std;

void solve(string s)
{
    int l,h;
    int start=0,end=1;
    for(int i=1;i<s.size();i++)
    {
        l=i-1;
        h=i;
        while(l>=0 and h<s.size() and s[l]==s[h])
        {
            if(h-l+1>end)
            {
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
        
        l=i-1;
        h=i+1;
        while(l>=0 and h<s.size() and s[l]==s[h])
        {
            if(h-l+1>end)
            {
                start=l;
                end=h-l+1;
            }
            l--;
            h++;
        }
    }
    
    for(int i=start;i<=start+end-1;i++)
    {
        cout<<s[i];
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
