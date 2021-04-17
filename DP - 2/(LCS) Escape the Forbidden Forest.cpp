// https://practice.geeksforgeeks.org/problems/a4f19ea532cee502aabec77c07e0d0a45b76ecf9/1/?track=30-DOC-day-30&batchId=320#
class Solution
{
    public:
    int dp[1001][1001];
    int solve(string s1,string s2,int n,int m)
    {
        if(n==0 or m==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]=1+solve(s1,s2,n-1,m-1);
        }
        else
        {
            return dp[n][m]=max(solve(s1,s2,n-1,m),solve(s1,s2,n,m-1));
        }
    }
    
    int build_bridges(string str1, string str2)
    {
        memset(dp,-1,sizeof(dp));
        int n=str1.size();
        int m=str2.size();
        
        return solve(str1,str2,n,m);
        // code here
    }
};
