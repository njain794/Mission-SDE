#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin>>n;
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<int>>minh;
    
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        if(maxh.empty() or maxh.top()>m)
        {
            maxh.push(m);
        }
        else
        {
            minh.push(m);
        }
        
        if(maxh.size()>minh.size()+1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        else if(minh.size()>maxh.size()+1)
        {
            maxh.push(minh.top());
            minh.pop();
        }
        
        if(minh.size()==maxh.size())
        {
            cout<<(minh.top()+maxh.top())/2;
        }
        else if(minh.size()>maxh.size())
        {
            cout<<minh.top();
        }
        else
        {
            cout<<maxh.top();
        }
        cout<<"\n";
    }
	//code
	return 0;
}
