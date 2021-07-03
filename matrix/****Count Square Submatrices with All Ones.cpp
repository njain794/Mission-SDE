class Solution {
public:
    int countSquares(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        
        int dp[n+1][m+1];
        dp[0][0]=mat[0][0];
        for(int i=1;i<n;i++)
        {
            //dp[0][i]=mat[0][i]+dp[0][i-1];
            dp[i][0]=mat[i][0]+dp[i-1][0];
        }
        for(int j=1;j<m;j++)
        {
            dp[0][j]=mat[0][j]+dp[0][j-1];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+mat[i][j]-dp[i-1][j-1];
            }
        }

        int ans=INT_MIN;
        int cnt=0;
        int sum;
        for(int k=min(n,m);k>=1;k--)
        {
            for(int i=k-1;i<n;i++)
            {
                for(int j=k-1;j<m;j++)
                {
                    if(i-k<0&&j-k<0)
                    sum=dp[i][j];
                    else if(i-k<0)
                    sum=dp[i][j]-dp[i][j-k];
                    else if(j-k<0)
                    sum=dp[i][j]-dp[i-k][j];
                    else if(i-k>=0 and j-k>=0)
                    {
                        sum=(dp[i][j]-dp[i-k][j]-dp[i][j-k]+dp[i-k][j-k]);
                        //ans=max(sum,ans);
                    }
                    if(sum==(k)*(k))
                    {
                        cnt++;
                    }
                }
            } 
        }
        return cnt;
    }
};
