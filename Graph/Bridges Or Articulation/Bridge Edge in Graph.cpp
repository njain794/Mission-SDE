void dfs(vector<int>adj[], int node, int vis[]) {
vis[node] = 1;
for (auto i : adj[node]) {
if (!vis[i])
dfs(adj, i, vis);
}
}
int isBridge(int V, vector<int> adj[], int c, int d)
{

for (int i = 0; i < adj[c].size(); i++) {
if (adj[c][i] == d)
{
adj[c].erase(adj[c].begin() + i);
break;
}
}
for (int i = 0; i < adj[c].size(); i++) {
if (adj[d][i] == c)
{
adj[c].erase(adj[c].begin() + i);
break;
}
}

int vis[V] = {0};
dfs(adj, c, vis);
if (vis[d])
return 0;
return 1;

}
