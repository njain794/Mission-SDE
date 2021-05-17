long long dp[N+1];
    dp[0] = 1;
    
    for(int i = 1; i <= N; i++)
    {
        dp[i] = 0;
        
        for(int j = 0; j < i; j++)
        {
            long long sub_res = (dp[j] * dp[i-1-j])%1000000007;
            dp[i] = (dp[i] + sub_res)%1000000007; 
        }
    }
    
    return int(dp[N]);
