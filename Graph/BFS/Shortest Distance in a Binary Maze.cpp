class Solution {
  public:
  
    bool isSafe(int x, int y, int n,int m)
    {
        return (x>=0 && x<n && y>=0 && y<m);
    }
  
    int shortestPath(vector<vector<int>>&grid,pair<int,int>source,pair<int,int>destination) 
    {
        if(source==destination)
        {
            return 0;
        }
        
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<pair<int,int>,int>>q;
        q.push({source,0});
        
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            
            int i=curr.first.first;
            int j=curr.first.second;
            int dis=curr.second;
            
            if(i==destination.first && j==destination.second)
            {
                return dis;
            }
            
            for(int k=0;k<4;k++)
            {
                int a=i+dx[k];
                int b=j+dy[k];
                if(isSafe(a,b,n,m) && grid[a][b]==1)
                {
                    q.push({{a,b},dis+1});
                    grid[a][b]=0;
                }
            }
        }
        return -1;
    }
};
