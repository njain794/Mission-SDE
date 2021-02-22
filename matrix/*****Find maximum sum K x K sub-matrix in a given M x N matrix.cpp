int Maximum_Sum(vector<vector<int>> &mat,int n,int k)
{
    int dp[n+1][n+1];
    dp[0][0]=mat[0][0];
    for(int i=1;i<n;i++)
    {
        dp[0][i]=mat[0][i]+dp[0][i-1];
        dp[i][0]=mat[i][0]+dp[i-1][0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+mat[i][j]-dp[i-1][j-1];
        }
    }
    
    int ans=INT_MIN;
    for(int i=k-1;i<n;i++)
    {
        for(int j=k-1;j<n;j++)
        {
            if(i-k>=0 and j-k>=0)
            {
                int sum=(dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
                ans=max(sum,ans);
            }
        }
    }
    return ans;
}
