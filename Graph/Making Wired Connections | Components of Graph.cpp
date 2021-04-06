class Solution {
public:
    
    void dfs(vector<int> graph[],vector<int> &vis,int start)
    {
        vis[start]=1;
        for(auto x:graph[start])
        {
            if(!vis[x])
            {
                dfs(graph,vis,x);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& edges) 
    {
         int m=edges.size();
         if(m<n-1)
         {
             return -1;
         }
         vector<int>graph[n];
        
         for(int i=0;i<m;i++)
         {
             graph[edges[i][0]].push_back(edges[i][1]);
             graph[edges[i][1]].push_back(edges[i][0]);
         }
        
         vector<int>vis(n,0);
         int c=0;   
         for(int i=0;i<n;i++)
         {
             if(!vis[i])
             {
                 c++;
                 dfs(graph,vis,i);
             }
         }
         return c-1;
    }
};
