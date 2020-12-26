#include <bits/stdc++.h>
using namespace std;

string solve(string str)
{
    unordered_map<char,int>mp;
    priority_queue<pair<int,int>>maxh;
    string temp;
    for(int i=0;i<str.size();i++)
    {
        mp[str[i]]++;
    }
    for(auto x:mp)
    {
        maxh.push({x.second,x.first});
    }
    while(!maxh.empty())
    {
        pair<int,char>p=maxh.top();
        maxh.pop();
        if(p.first>0)
        {
            temp.push_back(p.second);
            p.first-=1;
        }
        if(!maxh.empty())
        {
            pair<int,char>p2=maxh.top();
            maxh.pop();
            if(p2.first>0)
            {
                temp.push_back(p2.second);
                p2.first-=1;
            }
            if(p2.first>0)
            {
                maxh.push(p2);
            }
        }
        if(p.first>0)
        {
            maxh.push(p);
        }
    }
    if(temp.size()==str.size())
    {
        return temp;
    }
    else
    {
        return "aa";
    }
}
bool check(string temp)
{
    for(int i=1;i<temp.size();i++)
    {
        if(temp[i-1]==temp[i])
        {
            return false;
        }
    }
    return true;
}
int main() 
{
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        string temp=solve(str);
        if(check(temp))
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"0\n";
        }
    }
	//code
	return 0;
}
