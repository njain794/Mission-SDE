
////////////////////// BFS SOLUTION ///////////////////////

class Solution{
	public:
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
        vector<int>in(v,0);
        vector<int>ans;
        
        for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
            {
                in[x]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            
            for(auto x:adj[curr])
            {
                in[x]--;
                if(in[x]==0)
                {
                    q.push(x);
                }
            }
        }
        
        return ans;
	    // code here
	}
};


/////////////// DFS SOLUTION ////////////////


// The Graph structure is as folows

/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*/
void solve(vector<int>adj[],int v,int start,bool vis[],stack<int>&st)
{
    vis[start] = true;
    for(auto node : adj[start])
    {
        if(!vis[node])
        {
            solve(adj,v,node,vis,st);
        }
    }
    st.push(start);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    bool vis[V];
    stack<int>st;
    
    for(int i=0;i<V;i++)
    {
        vis[i] = false;
    }
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            solve(adj,V,i,vis,st);
        }
    }
    vector<int>v;
    while(!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    return v;
    // Your code here
}
