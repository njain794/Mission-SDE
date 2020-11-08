/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) 
{
    vector<int>v;
    bool vis[N];
    queue<int>q;
    for(int i=0;i<N;i++)
    {
        vis[i] = false;
    }
    q.push(0);
    
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        v.push_back(temp);
        for(int i=0;i<g[temp].size();i++)
        {
            if(!vis[g[temp][i]])
            {
                q.push(g[temp][i]);
                vis[g[temp][i]] = true;
            }
        }
    }
    return v;
    // Your code here
}
