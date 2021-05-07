bool issafe(bool graph[101][101],int vis[],int v,int i,int j)
{
    for(int k=0;k<v;k++)
    {
        if(graph[i][k] and vis[k]==j)
        {
            return false;
        }
    }
    return true;
}

bool solve(bool graph[101][101],int vis[],int v,int m,int i)
{
    if(i==v)
    {
        return true;
    }
    for(int j=0;j<m;j++)
    {
        if(issafe(graph,vis,v,i,j))
        {
            vis[i]=j;
            if(solve(graph,vis,v,m,i+1))
            {
                return true;
            }
            vis[i]=-1;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int v)
{
    int vis[v];
    memset(vis,1,sizeof(vis));
    return solve(graph,vis,v,m,0);
    // your code here
}
