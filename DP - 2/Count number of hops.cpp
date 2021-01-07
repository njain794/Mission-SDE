long long countWays(int n)
{
    long long int dp[n+5];
    long long int mod=1000000007;
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod+dp[i-3]%mod)%mod;
    }
    return dp[n];
    
    // your code here
    
}
