class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        int l1=s1.size();
        int l2=s2.size();
        int l3=s3.size();
        
        if(l1+l2!=l3)
        {
            return false;
        }
        
        int dp[l1+1][l2+1];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=l1;i++)
        {
            for(int j=0;j<=l2;j++)
            {
                if(i==0 and j==0)
                {
                    dp[i][j]=1;
                }
                
                else if(i==0)
                {
                    if(s3[j-1]==s2[j-1])
                    {
                        dp[i][j]=dp[i][j-1];
                    }
                }
                
                else if(j==0)
                {
                    if(s3[i-1]==s1[i-1])
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                }
                
                else if(s1[i-1]==s3[i+j-1] and s2[j-1]!=s3[i+j-1])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else if(s2[j-1]==s3[i+j-1] and s1[i-1]!=s3[i+j-1])
                {
                    dp[i][j]=dp[i][j-1];
                }
                else if(s1[i-1]==s3[i+j-1] and s2[j-1]==s3[i+j-1])
                {
                    dp[i][j]=dp[i-1][j] or dp[i][j-1];
                }
            }
        }
        return dp[l1][l2];
        
    }
};
