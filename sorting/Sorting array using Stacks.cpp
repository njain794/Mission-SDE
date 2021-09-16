#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>&s,int val)
{
    if(s.size()==0 or s.top()>val)
    {
        s.push(val);
        return;
    }
    int v=s.top();
    s.pop();
    insert(s,val);
    s.push(v);
}

void sorto(stack<int>&s)
{
    if(s.size()==0 or s.size()==1)
    {
        return;
    }
    int val=s.top();
    s.pop();
    sorto(s);
    insert(s,val);
}

void sort(int arr[],int n)
{
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        s.push(arr[i]);
    }
    sorto(s);
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}

int main() {
    int arr[5]={7,20,1,8,3};
    sort(arr,5);
    //cout<<"Hello World!";
}
