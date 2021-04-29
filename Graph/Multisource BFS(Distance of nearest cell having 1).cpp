class Solution {
public:
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int>> res(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>>q;
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j});
	                res[i][j]=0;
	            }
	        }
	    }
	    
	    vector<pair<int,int>>moves = {{0,1},{1,0},{0,-1},{-1,0}};
	    
	    while(!q.empty())
	    {
	        auto p=q.front();
	        int x0=p.first;
	        int y0=p.second;
	        
	        q.pop();
	        for(auto mov:moves)
	        {
	            int x=x0+mov.first;
	            int y=y0+mov.second;
	            
	            if(x>=0 and x<n and y>=0 and y<m)
	            {
	                if(res[x][y]>res[x0][y0]+1)
	                {
	                    res[x][y]=res[x0][y0]+1;
	                    q.push({x,y});
	                }
	            }
	        }
	    }
	    return res;
	    // Code here
	}
};
