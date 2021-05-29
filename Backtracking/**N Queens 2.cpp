class Solution {
public:
    int ans=0;
    
    bool issafe(int &row,int &col,int dp[][10],int &n)
    {
        for(int i=0; i<row; i++)
        {
            if(dp[i][col])
                return false;
        }
        
        // checking for left diagonal
        for(int i=row, j=col; i>=0 and j>=0; i--, j--)
        {
            if(dp[i][j])
                return false;
        }
        
        //checking for Right diagonal
        for(int i=row, j=col; i>=0 and j<n; i--, j++)
        {
            if(dp[i][j])
                return false;
        }
        return true;
    }
    
    void solve(int dp[][10],int row,int &n)
    {
        if(row==n)
        {
            ans++;
            return;
        }
        
        for(int j=0;j<n;j++)
        {
            if(issafe(row,j,dp,n))
            {
                dp[row][j]=1;
                solve(dp,row+1,n);
                dp[row][j]=0;
            }
        }
    }
    
    int totalNQueens(int n) 
    {
        int dp[10][10]={0};
        //memset(dp,0,n+1);
        
        solve(dp,0,n);
        return ans;
    }
};
