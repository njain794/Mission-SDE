class Solution {
public:
    int countNumbersWithUniqueDigits(int n) 
    {
        if(n==0)
        {
            return 1;
        }
        int dp[9];
        dp[0]=1;
        int d=0,nd=1;
        
        for(int i=1;i<=8;i++)
        {
            d=d*10 + (i-1)*nd;
            nd=pow(10,i)-pow(10,i-1)-d;
            dp[i]=nd;
        }
        
        for(int i=1;i<=8;i++)
        {
            dp[i]=dp[i-1]+dp[i];
        }
        return dp[n];
    }
};
