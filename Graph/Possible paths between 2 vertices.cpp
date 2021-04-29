class Solution {
public:
	int countPaths(int n, vector<int> adj[], int src, int dest) 
	{
	    queue<int>q;
	    q.push(src);
	    int path=0;
	    
	    while(!q.empty())
	    {
	        int len=q.size();
	        while(len--)
	        {
	            int temp=q.front();
	            q.pop();
	            if(temp==dest )
	            {
	                path++;
	            }
	            else
	            {
	                for(auto x:adj[temp])
	                {
	                    q.push(x);
	                }
	            }
	        }
	    }
	    return path;
	    // Code here
	}
};
