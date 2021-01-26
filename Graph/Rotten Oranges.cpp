class Solution {
public:

    bool isfresh(vector<vector<int>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        return (i>=0 and i<n and j>=0 and j<m and grid[i][j]==1);
    }

    int orangesRotting(vector<vector<int>>& grid) 
    {
        int time=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    grid[i][j]=3;
                }
            }
        }
        
        int count = q.size();
        
        while(count>0)
        {
            for(int k=0;k<count;k++)
            {
                pair<int,int>p=q.front();
                int i=p.first;
                int j=p.second;
                
                if(isfresh(grid,i,j+1))
                {
                    q.push({i,j+1});
                    grid[i][j+1]=3;
                }
                if(isfresh(grid,i+1,j))
                {
                    q.push({i+1,j});
                    grid[i+1][j]=3;
                }
                if(isfresh(grid,i,j-1))
                {
                    q.push({i,j-1});
                    grid[i][j-1]=3;
                }
                if(isfresh(grid,i-1,j))
                {
                    q.push({i-1,j});
                    grid[i-1][j]=3;
                }
                q.pop();
            }
            count=q.size();
            if(count>0)
            {
                time++;
            }
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        
        return time;
        // Code here
    }
};
