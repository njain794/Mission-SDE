class Solution {
public:

    void solve(int i,int j,int &l,vector<vector<int>> &mat,vector<vector<int>> &vis,int n,int m)
    {
        if(i>n-1 or i<0 or j>m-1 or j<0)
        {
            return;
        }
        if(mat[i][j]==0 or vis[i][j]==1)
        {
            return;
        }
        else if(mat[i][j]==1)
        {
            l++;
        }
        
        vis[i][j]=1;
        solve(i-1,j,l,mat,vis,n,m);
        solve(i-1,j+1,l,mat,vis,n,m);
        solve(i-1,j-1,l,mat,vis,n,m);
        solve(i,j-1,l,mat,vis,n,m);
        solve(i,j+1,l,mat,vis,n,m);
        solve(i+1,j,l,mat,vis,n,m);
        solve(i+1,j-1,l,mat,vis,n,m);
        solve(i+1,j+1,l,mat,vis,n,m);
        //vis[i][j]=0;
    }

    int findMaxArea(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int res=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 and vis[i][j]==false)
                {
                    int l=0;
                    solve(i,j,l,grid,vis,n,m);
                    res=max(res,l);
                }
            }
        }
        return res;
        // Code here
    }
};
