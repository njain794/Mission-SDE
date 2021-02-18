// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n)
{
    //O(n) method
    if(arr[0]==0)
    {
        return -1;
    }
    if(n==1)
    {
        return 0;
    }
    int jumps=0,currend=0,farthest=0;
    for(int i=0;i<n-1;i++)
    {
        farthest=max(farthest,arr[i]+i);
        if(farthest>=n-1)
        {
            return 1+jumps;
        }
        if(i==currend)
        {
            jumps++;
            currend=farthest;
        }
        if(currend>=n-1)
        {
            break;
        }
    }
    if(currend<n-1)
    {
        return -1;
    }
    return jumps;
    
    //O(n^2) - method
    
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
