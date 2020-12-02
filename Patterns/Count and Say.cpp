#include <iostream>
using namespace std;

string solve(int n)
{
    if(n==1)
    {
        return "1";
    }
    if(n==2)
    {
        return "11";
    }
    string s="11";
    for(int i=3;i<=n;i++)
    {
        s=s+"&";
        string res="";
        int count=1;
        for(int j=1;j<s.length();j++)
        {
            if(s[j]!=s[j-1])
            {
                res=res+to_string(count);
                res=res+s[j-1];
                count=1;
            }
            else
            {
                count++;
            }
        }
        s=res;
    }
    return s;
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s=solve(n);
        cout<<s<<"\n";
    }
	//code
	return 0;
}
