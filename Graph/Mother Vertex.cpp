class Solution {
public:

    void dfs(int start,vector<int>adj[],vector<bool>&vis)
    {
        vis[start]=true;
        for(auto x:adj[start])
        {
            if(!vis[x])
            {
                dfs(x,adj,vis);
            }
        }
    }

	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool>vis(V,false);
	    
	    int last_dfs=0;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==false)
	        {
	            dfs(i,adj,vis);
	            last_dfs=i;
	        }
	    }
	    
	    for(int i=0;i<V;i++)
	    {
	        vis[i]=false;
	    }
	    
	    dfs(last_dfs,adj,vis);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==false)
	        {
	            return -1;
	        }
	    }
	    
	    return last_dfs;
	    // Code here
	}

};
