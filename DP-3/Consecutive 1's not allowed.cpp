class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    
    int solve(vector<vector<int>> &grid,int n,int m,int i,int j)
    {
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0)
        {
            return 0;
        }
        int val=grid[i][j];
        grid[i][j]=0;
        int mx=0;
        
        for(int k=0;k<4;k++)
        {
            mx=max(mx,solve(grid,n,m,i+dx[k],j+dy[k]));
        }
        grid[i][j]=val;
        return val+mx;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int temp=solve(grid,n,m,i,j);
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};
