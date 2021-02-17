int countWays(int n, int m)
	    {
	        if(n<m)
	        {
	            return 1;
	        }
	        else
	        {
	            return (countWays(n-1,m) + countWays(n-m,m));
	        }
      }    

#define mod 1000000007;
class Solution{
	public:
		int countWays(int n, int m)
	    {
	        if(n<m)
	        {
	            return 1;
	        }
	        int dp[n+1];
	        dp[0]=1;
	        for(int i=1;i<=n;i++)
	        {
	            if(i-m>=0)
	            {
	                dp[i]=(dp[i-1]+dp[i-m])%mod;
	            }
	            else
	            {
	                dp[i]=dp[i-1];
	            }
	        }
	        return dp[n];
	       // Code here.
	    }
};
