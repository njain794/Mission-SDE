
/// Shortest path in a weighted graph from source to destination////////////////////

/////// Using Priority-Queue ///////////////

#include<bits/stdc++.h>
using namespace std;

#define ppi pair<int,pair<int,string>>

void solve(vector<vector<int>>&mat,int n)
{
	vector<bool>vis(n,false);

	priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
	string s;
	s.push_back(0+'0');
	pq.push({0,{0,s}});
	string ans;
	int wt=0;
	while(!pq.empty())
	{
		auto p=pq.top();
		pq.pop();
		int w=p.first;
		int v=p.second.first;
		string path=p.second.second;

		if(vis[v]==true)
		{
			continue;
		}
		vis[v]=true;
		ans=path;
		wt=w;

		for(int i=0;i<n;i++)
		{
			if(mat[v][i]!=0 and !vis[i])
			{
				char b=i+'0';
				path.push_back(b);
				pq.push({w+mat[v][i],{i,path}});
			}
		}
	}
	cout<<wt<<"\n";
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}
int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		vector<vector<int>>mat(n,vector<int>(n,0));

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int e;
				cin>>e;
				mat[i][j]=e;
			}
		}

		solve(mat,n);
		cout<<"\n";
	}
}



////// Using SET /////////////

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int>dist(v,INT_MAX);
        dist[s]=0;
        
        set<pair<int,int>>st;
        st.insert({0,s});
        
        while(!st.empty())
        {
            auto p=*(st.begin());
            
            int dis=p.first;
            int node=p.second;
            st.erase(st.begin());
            
            for(auto child:adj[node])
            {
                if(dis+child[1]<dist[child[0]])
                {
                    int dest=child[0];
                    if(st.find({dist[dest],dest})!=st.end())
                    {
                        st.erase({dist[dest],dest});
                    }
                    dist[dest]=dis+child[1];
                    st.insert({dist[dest],dest});
                }
            }
            
            
        }
        return dist;
        // Code here
    }
};
