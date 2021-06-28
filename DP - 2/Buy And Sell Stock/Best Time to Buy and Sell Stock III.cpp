class Solution {
public:
    int maxProfit(vector<int>& arr) 
    {
        
        int n=arr.size();
        if(n<=1)
        {
            return 0;
        }
        
        int s1=-arr[0];
        int s2=INT_MIN;
        int s3=INT_MIN;
        int s4=INT_MIN;
        
        for(int i=1;i<n;i++)
        {
            s1=max(s1,-arr[i]);
            s2=max(s2,s1+arr[i]);
            s3=max(s3,s2-arr[i]);
            s4=max(s4,s3+arr[i]);
        }
        return max(0,s4);
        /*int n=arr.size();
        int dp[3][n+1];   
        
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        
        for(int j=0;j<=2;j++)
        {
            dp[j][0]=0;
        }
        
        for(int i=1;i<=2;i++)
        {
            int maxdiff=dp[i-1][0]-arr[0];
            for(int j=1;j<n;j++)
            {
                maxdiff=max(maxdiff,dp[i-1][j]-arr[j]);
                dp[i][j]=max(dp[i][j-1],maxdiff+arr[j]);
            }
        }
        return dp[2][n-1];*/
    }
};
