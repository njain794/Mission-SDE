#include <bits/stdc++.h>
using namespace std;

void solve(long long int n)
{
    
   long long int arr[n+1];
   for(int i=2;i<=n;i++)
   {
       arr[i]=i;
   }
   for(int i=2;i<=n;i++)
   {
       if(arr[i]==i)
       {
           for(int j=i*i;j<=n;j+=i)
           {
               arr[j]=i;
           }
       }
   }
   set<int>st;
  // vector<int>v;
   while(n!=1)
   {
       //v.push_back(arr[n]);
       st.insert(arr[n]);
       n=n/arr[n];
   }
   
   for(auto it=st.begin();it!=st.end();it++)
   {
       cout<<(*it)<<" ";
   }
   //auto it=unique(v.begin(),v.end());
   //v.resize(distance(v.begin(),it));
   //sort(v.begin(),v.end());
   /*for(auto x:v)
   {
       cout<<x<<" ";
   }*/
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        solve(n);
        cout<<"\n";
    }
	//code
	return 0;
}
