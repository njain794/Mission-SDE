vector<int> solve(vector<pair<int,int>> adj[],int n,int src)
    {
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[src]=0;
        
        pq.push({0,src});
        
        while(!pq.empty())
        {
            auto top=pq.top();
            int node=top.second;
            pq.pop();
            
            for(auto nodeVal: adj[node])
            {
                int v=nodeVal.first;
                int wt=nodeVal.second;
                if(dist[node]+wt<dist[v])
                {
                    dist[v]=dist[node]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
  
    int minimumCost(vector<vector<int>>& flights, int n, int k) 
    {
        vector<pair<int,int>>adj[n];
        
        for(auto x:flights)
        {
            int u=x[0]-1;
            int v=x[1]-1;
            int w=x[2];
            
            adj[u].push_back({v,w});
        }
        
        auto ans = solve(adj,n,k-1);
        
        int res = *max_element(ans.begin(),ans.end());
        return res==INT_MAX?-1:res;
    }
