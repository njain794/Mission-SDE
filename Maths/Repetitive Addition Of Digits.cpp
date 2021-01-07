#include <iostream>
using namespace std;

void solve(int n)
{
   if(n<10)
   {
       cout<<n;
       return;
   }
   while(n>9)
   {
       int val=0;
       while(n>0)
       {
           val+=n%10;
           n=n/10;
       }
       n=val;
   }
   cout<<n;
   return;
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
