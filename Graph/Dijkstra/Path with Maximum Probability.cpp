class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) 
    {
        vector<vector<pair<int,double>>> graph(n);
        vector<double> prob(n,0.0);
        
        int i=0;
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            double wt=succ[i];
            
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
            i++;
        }
        
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        prob[start]=1.0;
        
        while(!pq.empty())
        {
           auto p=pq.top();
           pq.pop();
            
           if(p.second==end)
           {
               return p.first;
           }
            
           for(auto x:graph[p.second])
           {
               double w=p.first*x.second;
               
               if(w > prob[x.first])
               {
                   prob[x.first]=w;
                   pq.push({w,x.first});
               }
               
           }
        }
        
        return 0.0;
        
    }
};
