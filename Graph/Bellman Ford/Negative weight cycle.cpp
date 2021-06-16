class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    vector<int>dist(n,100000000);
	    
	    for(int i=0;i<n;i++)
	    {
	        bool flag=true;
	        for(auto e:edges)
	        {
	            int u=e[0];
	            int v=e[1];
	            int w=e[2];
	            
	            if(dist[v]>dist[u]+w)
	            {
	                flag=false;
	                dist[v]=dist[u]+w;
	            }
	        }
	        if(flag)
	        {
	            break;
	        }
	    }
	    for(auto e:edges)
	    {
	        int u=e[0];
	        int v=e[1];
	        int w=e[2];
	            
	            if(dist[v]>dist[u]+w)
	            {
	                return true;
	            }
	    }
	    return false;
	    // Code here
	}
};
