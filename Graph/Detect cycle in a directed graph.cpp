/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool solve(vector<int> adj[],int V,int start,bool vis[],bool anc[])
{
    vis[start] = true;
    anc[start] = true;
    
    for(auto node : adj[start])
    {
        if(!vis[node])
        {
            if(solve(adj,V,node,vis,anc))
            {
                return true;
            }
        }
        else if(anc[node])
        {
            return true;
        }
    }
    anc[start] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    bool vis[V];
    bool anc[V];
    for(int i=0;i<V;i++)
    {
        vis[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(solve(adj,V,i,vis,anc))
            {
                return true;
            }
        }
    }
    return false;
    // Your code here
}
