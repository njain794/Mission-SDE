class Solution {
public:

    bool dfs(int src,vector<int>adj[],vector<int>&vis,int col)
    {
        vis[src]=col;
        
        for(auto x:adj[src])
        {
            if(vis[x]==-1)
            {
                if(!dfs(x,adj,vis,3-col))
                {
                    return false;
                }
            }
            else if(vis[x]==vis[src])
            {
                return false;
            }
        }
        return true;
    }

	bool isBipartite(int v, vector<int>adj[])
	{
	    vector<int>vis(v,-1);
	    
	    for(int i=0;i<v;i++)
	    {
	       if(vis[i]==-1)
	       {
	           if(!dfs(i,adj,vis,1))
	           {
	               return false;
	           }
	       }
	    }
	    return true;
	    // Code here
	}

};
