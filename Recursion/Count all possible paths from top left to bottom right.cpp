#include <bits/stdc++.h>
using namespace std;

int paths(int n,int m,int i,int j)
{
    long long int dp[n][m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 or j==0)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
            }
        }
    }
    return dp[n-1][m-1];
    /*if(i==n-1 and j==m-1)
    {
        return 1;
    }
    if(i>=n or j>=m)
    {
        return 0;
    }
    
    return (paths(n,m,i+1,j)+paths(n,m,i,j+1))%1000000007;*/
}

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,m;
        cin>>n;
        cin>>m;
        int i=0,j=0;
        cout<<paths(n,m,i,j)<<"\n";
    }
    
	//code
	return 0;
}
