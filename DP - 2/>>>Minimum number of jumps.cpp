// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n)
{
    if(n==0)
    {
        return 0;
    }
    int dp[n+1];
    dp[0]=0;
    
    for(int i=1;i<n;i++)
    {
        dp[i]=INT_MAX;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(dp[j]!=INT_MAX and arr[j]+j>=i)
            {
                if(dp[j]+1<dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
    }
    if(dp[n-1]==INT_MAX)
    {
        return -1;
    }
    else
    {
        return dp[n-1];
    }
    // Your code here
}
