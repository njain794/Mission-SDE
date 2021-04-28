class Solution {
public:
	int levelOfX(int n, vector<int> adj[], int X) 
	{
	    bool vis[n];
	    queue<int>q;
	    
	    for(int i=0;i<n;i++)
	    {
	        vis[i]=false;
	    }
	    q.push(0);
	    //q.push(-1);
	    int level=0;
	    
	    while(!q.empty())
	    {
	        int len=q.size();
	        while(len--)
	        {
	            int temp=q.front();
	            q.pop();
	            vis[temp]=true;
	            if(temp==X)
	            {
	                return level;
	            }
	            
	            for(auto x:adj[temp])
	            {
	                if(!vis[x])
	                {
	                    q.push(x);
	                }     
	            }
	        }
	        level++;
	    }
	    return -1;
	    // Code here
	}
};
