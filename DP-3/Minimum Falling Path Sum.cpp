class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //memset(dp,n,0);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==n-1)
                {
                    dp[i][j]=mat[i][j];
                }
                else if(j==n-1)
                {
                    dp[i][j]=min(dp[i+1][j],dp[i+1][j-1])+mat[i][j];
                }
                else if(j==0)
                {
                    dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+mat[i][j];
                }
                else
                {
                    dp[i][j]=min(dp[i+1][j],min(dp[i+1][j-1],dp[i+1][j+1]))+mat[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};
