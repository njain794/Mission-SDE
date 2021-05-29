class Solution{
public:
    int dp[101][101];
    
    int solve(int i,int j,int arr[])
    {
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=solve(i,k,arr)+solve(k+1,j,arr)+(arr[i-1]*arr[k]*arr[j]);
            mn=min(mn,temp);
        }
        dp[i][j]=mn;
        return dp[i][j];
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }
        return solve(1,n-1,arr);
        // code here
    }
};
