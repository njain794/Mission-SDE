class Solution {
public:
    int numDecodings(string s) 
    {
        if(s[0]-'0'==0)
        {
            return 0;
        }
        int n=s.size(); 
        vector<int>dp(n+1,0);
        dp[0]=1;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='0' and s[i-1]=='0')
            {
                return 0;
            }
            
            int a=s[i-1]-'0';
            int b=s[i]-'0';
            
            int val=(a*10)+b;
            if(val>=10 and val<=26)
            {
                if(i==1)
                {
                    dp[i]+=1;
                }
                else
                {
                    dp[i]+=dp[i-2];
                }
            }
            if(s[i]!='0')
            {
                dp[i]+=dp[i-1];
            }
        }
        return dp[n-1];
    }
};
