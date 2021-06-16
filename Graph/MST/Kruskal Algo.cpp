class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int find(int i,vector<int>&parent)
    {
        if(parent[i]==-1)
        {
            return i;
        }
        return parent[i]=find(parent[i],parent);
    }
    
    void unite(int x,int y,vector<int>&parent,vector<int>&rank)
    {
        int s1=find(x,parent);
        int s2=find(y,parent);
        
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int>parent(v,-1);
        vector<int>rank(v,1);
        vector<vector<int>>graph;
        int cost=0;
        
        for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
            {
                int u=i;
                int v=x[0];
                int w=x[1];
                graph.push_back({w,u,v});
            }
        }
        
        sort(graph.begin(),graph.end());
        
        for(auto z:graph)
        {
            int wt=z[0];
            int s=z[1];
            int e=z[2];
            
            if(find(s,parent)!=find(e,parent))
            {
                unite(s,e,parent,rank);
                cost+=wt;
            }
        }
        
        return cost;
        // code here
    }
};
