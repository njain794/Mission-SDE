class Solution {
public:
    int dp[201][201];
    
    int dfs(vector<vector<int>> &mat,int i,int j,int val)
    {
        if(i<0 or i>=mat.size() or j<0 or j>=mat[0].size() or mat[i][j]<=val)
        {
            return 0;
        }
        
        if(dp[i][j])
        {
            return dp[i][j];
        }
        
        int da=mat[i][j];
        mat[i][j]=-1;
        
        int l=dfs(mat,i,j-1,da);
        int r=dfs(mat,i,j+1,da);
        int u=dfs(mat,i-1,j,da);
        int d=dfs(mat,i+1,j,da);
        
        mat[i][j]=da;
        return dp[i][j]=max({l,r,u,d})+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int maxval=0;
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                maxval=max(maxval,dfs(matrix,i,j,-1));
            }
        }
        
        return maxval;
    }
};
