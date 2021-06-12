class Solution {
public:
    
    //int dp[10001][10001];
    
    int solve(int l,int r,vector<int>& stone,vector<vector<int>> &dp)
    {
        if(l>=r)
        {
            return 0;
        }
        
        if(dp[l][r]!=INT_MAX)
        {
            return dp[l][r];
        }
        
        int ll=stone[l+1]+solve(l+2,r,stone,dp);
        int rr=stone[r-1]+solve(l,r-2,stone,dp);
        
        int lr=stone[r]+solve(l+1,r-1,stone,dp);
        int rl=stone[l]+solve(l+1,r-1,stone,dp);
        
        if(min(ll,lr)<min(rr,rl))
        {
            dp[l][r]=min(rr,rl);
        }
        else
        {
            dp[l][r]=min(ll,lr);
        }
        return dp[l][r];
    }
    
    int stoneGameVII(vector<int>& stone) 
    {
        int n=stone.size()-1;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
        
        return solve(0,n,stone,dp);
    }
};
