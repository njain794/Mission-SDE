int dp[1001][1001];
int solve(string s,int i,int j)
{
    if(i>j)
    {
        return 0;
    }
    if(i==j)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==s[j])
    {
        return dp[i][j] = 1+solve(s,i,j-1)+solve(s,i+1,j);
    }
    else
    {
        return dp[i][j] = solve(s,i,j-1)+solve(s,i+1,j)-solve(s,i+1,j-1);
    }
}
int countPS(string str)
{
    int n = str.length()-1;
    int start=0;
    int end=n;
    memset(dp,-1,sizeof(dp));
    return solve(str,start,end);
   //Your code here
}
