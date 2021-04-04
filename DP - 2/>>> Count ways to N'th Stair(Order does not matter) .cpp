long long countWays(int m)
{
    int dp[m+1];
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=m;i++)
    {
        dp[i]=1+dp[i-2];
    }
    return dp[m];
    
    //////////OR/////////////
    
    /*if(m==0 or m==1)
    {
        return 1;
    }
    return 1+countWays(m-2);*/
    
    //////////OR//////////
    
    // return (n/2)+1;
    // your code here
}
