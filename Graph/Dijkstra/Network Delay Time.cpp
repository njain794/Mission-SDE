#define ppi pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& time, int n, int k) 
    {
        vector<vector<pair<int,int>>> graph(n+1);
        
        for(int i=0;i<time.size();i++)
        {
            int a=time[i][0];
            int b=time[i][1];
            int c=time[i][2];
            
            graph[a].push_back({b,c});
        }
        
        vector<int>dist(n+1,INT_MAX);
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        
        pq.push({0,k});
        dist[k]=0;
        
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            
            int wt=p.first;
            int node=p.second;
            
            for(auto x:graph[node])
            {
                int w=dist[node]+x.second;
                if(w<dist[x.first])
                {
                    dist[x.first]=w;
                    pq.push({w,x.first});
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
            {
                return -1;
            }
        }
        return *max_element(dist.begin()+1,dist.end());
    }
};
