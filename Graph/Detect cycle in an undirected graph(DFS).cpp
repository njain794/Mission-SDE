/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool solve(vector<int> g[],int n,bool vis[],int start,int parent)
{
    vis[start]=true;
    
    for(auto x:g[start])
    {
        if(!vis[x])
        {
            if(solve(g,n,vis,x,start))
            {
                return true;
            }
        }
        else if(x!=parent)
        {
            return true;
        }
    }
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
    bool vis[V];
    for(int i=0;i<V;i++)
    {
        vis[i]=false;
    }
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(solve(g,V,vis,i,-1))
            {
                return true;
            }
        }
    }
    return false;
   // Your code here
   
}
