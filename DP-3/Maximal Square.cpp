class Solution {
public:
    int maximalSquare(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>mat(n,vector<int>(m,0));
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                mat[i][j]=grid[i][j]-'0';
            }
        }
        
        for(int j=0;j<m;j++)
        {
            dp[0][j]=mat[0][j];
        }
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=mat[i][0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    dp[i][j]=min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;
                }
                else
                {
                    dp[i][j]=0;
                }
            }
       }
        
        int mx=INT_MIN;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               mx=max(mx,dp[i][j]);
           }
       }
        return mx*mx;
    }
};
