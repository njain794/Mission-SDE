int solve(string x,string y,int n,int m)
{
    if(m==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(x[n-1]==y[m-1])
    {
        solve(x,y,n-1,m-1)+solve(x,y,n-1,m);
    }
    else
    {
        solve(x,y,n-1,m);
    }
}*/

int subsequenceCount(string S, string T)
{
    //int dp[1001][1001];
    //memset(dp,-1,sizeof(dp));
    int n=S.size();
    int m=T.size();
    int dp[n+1][m+1];
    
    for(int i=0;i<=m;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(S[i-1]==T[j-1])
            {
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
            }
            else
            {
                dp[i][j]=(dp[i-1][j])%1000000007;
            }
        }
    }
    return dp[n][m];
    //return solve(S,T,n,m);
  //Your code here
}
