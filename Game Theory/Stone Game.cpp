class Solution {
public:
    bool stoneGame(vector<int>& piles) 
    {
        
        int sum=0;
        for(auto s:piles)
        {
            sum+=s;
        }
        
        int n=piles.size();
        int dp[n][n];
        
        for(int gap=0;gap<n;gap++)
        {
            int i=0;
            for(int j=gap;j<n;j++)
            {
                if(gap==0)
                {
                    dp[i][j]=piles[i];   
                }
                else if(gap==1)
                {
                    dp[i][j]=max(piles[i],piles[j]);
                }
                else
                {
                    int val1=piles[i]+min(dp[i+2][j],dp[i+1][j-1]);
                    int val2=piles[j]+min(dp[i][j-1],dp[i+1][j-1]);
                    dp[i][j]=max(val1,val2);
                }
                i++;
            }
        }
        return (dp[0][n-1]>(sum-dp[0][n-1]));
    }
};
