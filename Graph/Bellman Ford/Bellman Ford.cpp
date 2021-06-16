class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int v, vector<vector<int>> adj, int s) 
    {
        vector<int>dist(v,100000000);
        dist[s]=0;
        
        for(int i=0;i<v-1;i++)
        {
            bool flag=true;
            for(auto x:adj)
            {
                int u=x[0];
                int v=x[1];
                int w=x[2];
                
                if(dist[v]>dist[u]+w)
                {
                    dist[v]=dist[u]+w;
                    flag=false;
                }
                
            }
            if(flag)
            {
                break;
            }
        }
        return dist;
        // Code here
    }
};
