class Solution {
public:
    int countSubstrings(string s) 
    {
        int n=s.size();
        bool dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++)
        {
            dp[i][i]=true;
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
            }
        }
        
        /*r(int i=0;i<n-3+1;i++)
        {
            for(int j=i+3-1;j<n;j++)
            {
                if(s[i]==s[j] and dp[i+1][j-1])
                {
                    dp[i][j]=true;
                }
            }
        }*/
        
        for(int i=n-3;i>=0;i--)
        {
            for(int j=n-1;j>=i+3-1;j--)
            {
                if(s[i]==s[j] and dp[i+1][j-1])
                {
                    dp[i][j]=true;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j])
                {
                    count++;
                }
            }
        }
        
        return count;
        
    }
};
