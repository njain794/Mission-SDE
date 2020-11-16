typedef long long ll;
long long minimumNumberOfCoins(int coin[],int numberOfCoins,int value)
{
    // your code here
    int n = numberOfCoins;
    ll dp[n+1][value+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=value; j++){
            if(j == 0)
                dp[i][j] = 0;
            if(i == 0)
                dp[i][j] = INT_MAX-1;
        }
    }
    
    for(int i=1; i<=value; i++){
        if(value%coin[0] == 0){
            dp[1][i] = value/coin[0];
        }
        else
            dp[1][i] = INT_MAX-1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=1; j<=value; j++){
            if(coin[i-1] <= j)
                dp[i][j] = min(dp[i][j-coin[i-1]]+1, dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return (dp[n][value] > 1000)? -1 : dp[n][value];
}


/*long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    int n=numberOfCoins;
    int v=value;
    long long dp[n+1][v+1];
    
    for(int i=1;i<=v;i++)
    {
        if(v%coins[0]==0)
        {
            dp[1][i]=v/coins[0];
        }
        else
        {
            dp[1][i] =INT_MAX-1;
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=v;j++)
        {
            if(j==0)
            {
                dp[i][j]=0;
                continue;
            }
            if(i==0)
            {
                dp[i][j]=INT_MAX-1;
                continue;
            }
            if(coins[i-1]<=j)
            {
                dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
        return (dp[n][value] > 1000)? -1 : dp[n][value];
        /*if(dp[n][v]==INT_MAX-1)
        {
            return -1;
        }
        else
        {
            return dp[n][v];
        }
    }
    // your code here
}*/
