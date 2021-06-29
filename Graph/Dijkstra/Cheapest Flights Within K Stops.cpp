#define ppi pair<int,pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>graph(n);
        
        for(auto x:flights)
        {
            graph[x[0]].push_back({x[1],x[2]});
        }
        
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        
        vector<int>dist(n,INT_MAX);
        pq.push({0,{src,0}});
        
        while(!pq.empty())
        {
            auto ver=pq.top();
            pq.pop();
            int u=ver.second.first;
            int w=ver.first;
            int stops=ver.second.second;
            
            if(u==dst)
            {
                return w;
            }
            if(stops>k)
            {
                continue;
            }
            if(dist[u]!=INT_MAX and dist[u]<stops)
            {
                continue;
            }
            dist[u]=stops;
            
            for(auto x:graph[u])
            {
                int v=x.first;
                int wt=x.second;
                
                pq.push({w+wt,{v,stops+1}});
                
            }
            
        }
        return -1;
    }
};
