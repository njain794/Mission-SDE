
    int uniquePathsWithObstacles(vector<vector<int>>& ob) 
    {
        int n=ob.size();
        int m=ob[0].size();
        if(ob[0][0]==1)
        {
            return 0;
        }
        if(n==0)
        {
            return 0;
        }
        
        int dp[n][m];
        
        dp[0][0]=1;
        
        for(int i=1;i<m;i++)
        {
            if(ob[0][i]==0)
            {
                dp[0][i]=dp[0][i-1];
            }
            else
            {
                dp[0][i]=0;
            }
        }
        
        for(int i=1;i<n;i++)
        {
           if(ob[i][0]==0)
           {
               dp[i][0]=dp[i-1][0];
           }
           else
            {
                dp[i][0]=0;
            }
        }
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(ob[i][j]==0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[n-1][m-1];
