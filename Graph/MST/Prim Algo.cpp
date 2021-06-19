#define ppi pair<int,int>

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<bool>vis(v,false);
        vector<int>dist(v,INT_MAX);
        dist[0]=0;
        
        priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
        pq.push({0,0});
        int cost=0;
        
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            
            int wt=p.first;
            int u=p.second;
            
            if(!vis[u])
            {
                vis[u]=true;
                cost+=wt;
                
                for(auto e:adj[u])
                {
                    if(!vis[e[0]] and dist[e[0]]>e[1])
                    {
                        dist[e[0]]=e[1];
                        pq.push({e[1],e[0]});
                    }
                }
            }
        }
        return cost;
        // code here
    }
};
