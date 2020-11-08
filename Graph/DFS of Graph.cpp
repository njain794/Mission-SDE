/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void solve(vector<int> g[],int N,vector<int>&v,int start,bool vis[])
{
    v.push_back(start);
    vis[start] = true;
    
    for(auto x: g[start])
    {
        if(!vis[x])
        {
            solve(g,N,v,x,vis);
        }    
    }
}
vector <int> dfs(vector<int> g[], int N)
{
    vector<int>v;
    int start = 0;
    bool vis[N];
    
    for(int i=0;i<N;i++)
    {
        vis[i] = false;
    }
    solve(g,N,v,start,vis);
    return v;
    // Your code here

}
