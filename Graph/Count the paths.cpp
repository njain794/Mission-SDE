//////******segmentation fault on submitting******///////
class Solution {

public:

    void dfs(vector<vector<int>>edges,int n,int s,int d,int &count,bool vis[])
    {
        if(s==d)
        {
            count++;
            return;
        }
        
        if(vis[s]==true)
        {
            return;
        }
        
        vis[s]=true;
        for(auto x:edges[s])
        {
            if(vis[x]==false)
            {
                dfs(edges,n,x,d,count,vis);
            }
        }
        vis[s]=false;
        return;
    }
    
	int possible_paths(vector<vector<int>>edges, int n, int s, int d)
	{
	    int count=0;
	    bool vis[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        vis[i]=false;
	    }
	    
	    dfs(edges,n,s,d,count,vis);
	    return count;
	    // Code here
	}
};
