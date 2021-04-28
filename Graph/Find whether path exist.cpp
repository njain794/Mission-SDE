class Solution {
public:

    bool solve(int n,vector<vector<int>> &vis,vector<vector<int>> &mat,int i,int j)
    {
        if(i>n-1 or i<0 or j>n-1 or j<0)
        {
            return false;
        }
        else if(mat[i][j]==0 or vis[i][j]==1)
        {
            return false;
        }
        else if(mat[i][j]==2)
        {
            return true;
        }
        
        vis[i][j]=1;
        bool b1=solve(n,vis,mat,i+1,j);
        bool b2=solve(n,vis,mat,i-1,j);
        bool b3=solve(n,vis,mat,i,j+1);
        bool b4=solve(n,vis,mat,i,j-1);
        
        //vis[i][j]=0;
        if(b1 or b2 or b3 or b4)
        {
            return true;
        }
        return false;
    }

    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return solve(n,vis,grid,i,j);
                }
            }
        }
        
        return false;
    }
