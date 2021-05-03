class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<int>adj[n];
        vector<int>in(n,0);
        
        for(auto v:pre)
        {
            adj[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            
            for(auto x:adj[curr])
            {
                in[x]--;
                if(in[x]==0)
                {
                    q.push(x);
                }
            }
        }
        
        return (ans.size()==n);
        
    }
};
