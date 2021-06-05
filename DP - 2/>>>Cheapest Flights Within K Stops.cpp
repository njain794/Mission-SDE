


//////////////DFS + Pruning (TLE) //////////////////////////
class Solution {
public:
    
    void solve(vector<vector<int>>adj,vector<vector<int>>cost,vector<bool>&vis,int src,int dst,int k,int amt,int &fare)
    {
        if(k<-1)
        {
            return;
        }
        if(src==dst)
        {
            fare=min(fare,amt);
            return;
        }
        vis[src]=true;
        
        for(auto x:adj[src])
        {
            if(!vis[x] and (fare>=amt+cost[src][x]))
            {
                solve(adj,cost,vis,x,dst,k-1,amt+cost[src][x],fare);
            }
        }
        vis[src]=false;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<int>>adj(n+1);  
        vector<vector<int>>cost(n+1,vector<int>(n+1));
            
        for(auto x:flights)
        {
            adj[x[0]].push_back(x[1]);
            cost[x[0]][x[1]]=x[2];
        }
        
        vector<bool>vis(n+1,false);
        int fare=INT_MAX;
        solve(adj,cost,vis,src,dst,k,0,fare);
        
        if(fare==INT_MAX)
        {
            return -1;
        }
        return fare;
    }
};
