int dp[1001][1001];
int solve(int a[],int n,int ans,int i)
{
    if(i==n)
    {
        return ans;
    }
    if(dp[i][ans]!=-1)
    {
        return dp[i][ans];
    }
    return dp[i][ans] = max(solve(a,n,ans^a[i],i+1),solve(a,n,ans,i+1));
}
int maxSubarrayXOR(int a[], int n)
{
    //int dp[n+1][n+1];
    memset(dp,-1,sizeof(dp));
    return solve(a,n,0,0);
}
