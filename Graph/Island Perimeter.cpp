class Solution {
public:
    
    void solve(int i,int j,int n,int m,int &cnt,vector<vector<int>> &grid)
    {
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j]==0)
        {
            cnt++;
            return;
        }
        if(grid[i][j]==-1)
        {
            return;
        }
        grid[i][j]=-1;
        
        solve(i+1,j,n,m,cnt,grid);
        solve(i-1,j,n,m,cnt,grid);
        solve(i,j+1,n,m,cnt,grid);
        solve(i,j-1,n,m,cnt,grid);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        //vector<vector<int>> vis(n,vector<int>(m,0));
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    solve(i,j,n,m,cnt,grid);
                    break;
                }
            }
        }
        return cnt;
    }
};
