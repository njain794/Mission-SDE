#define ppi pair<int,pair<int,int>>

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) 
    {
        int n=mat.size();
        priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({mat[i][0],{i,0}});
        }
        
        for(int i=1;i<k;i++)
        {
            auto p=pq.top();
            pq.pop();
            
            int val=p.first;
            int u=p.second.first;
            int v=p.second.second;
            
            if(v+1<n)
            {
               pq.push({mat[u][v+1],{u,v+1}}); 
            }
        }
        return pq.top().first;
    }
};
