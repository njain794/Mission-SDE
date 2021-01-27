class Solution {
public:

    bool dfs(vector<int>adj[],int start,vector<int>&col,int n,int cr)
    {
        bool flag=true;
        col[start]=cr;
        
        for(auto x:adj[start])
        {
            if(col[x]==-1)
            {
                flag=dfs(adj,x,col,n,1-cr);
                if(!flag)
                {
                    return false;
                }
            }
            if(col[x]==col[start])
            {
                return false;
            }
        }
        return true;
    }

	bool isBipartite(int n, vector<int>adj[])
	{
	    vector<int>col;
	    for(int i=0;i<n;i++)
	    {
	        col.push_back(-1);
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(col[i]==-1)
	        {
	            if(!dfs(adj,i,col,n,6))
	            {
	                return false;
	            }
	        }
	    }
	    return true;
	    // Code here
	}

};
