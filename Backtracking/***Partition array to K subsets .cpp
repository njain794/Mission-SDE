bool solve(int a[],int n,int sum)
{
    bool dp[n+1][sum+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j==0 or(i==0 and j==0))
            {
                dp[i][j]=true;
            }
            else if(i==0)
            {
                dp[i][j]=false;
            }
            else if(a[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j-a[i-1]] || dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
    
}

bool isKPartitionPossible(int a[], int n, int k)
{
    if(k==1)
    {
        return true;
    }
    else if(n<k)
    {
        return false;
    }
    
    int sum=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    if(sum%k!=0)
    {
        return false;
    }
    else if(a[n-1]>sum/k)
    {
        return false;
    }
    else
    {
        return solve(a,n,sum/k);
    }
     //Your code here
}
