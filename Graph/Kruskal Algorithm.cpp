#include <bits/stdc++.h>
using namespace std;

class dsu{
        int *parent;
        int *rank;
    public:
        dsu(int n)
        {
            parent = new int[n];
            rank = new int[n];

            for(int i=0;i<n;i++)
            {
                parent[i]=-1;
                rank[i]=1;
            }
        }

        int find(int i)
        {
            if(parent[i]==-1)
            {
                return i;
            }
            return parent[i]=find(parent[i]);
        }

        void unite(int x,int y)
        {
            int s1=find(x);
            int s2=find(y);

            if(s1!=s2)
            {
                if(rank[s1]<rank[s2])
                {
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
                else
                {
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
};

class graph{
        vector<vector<int>>edgelist;
        int v;
    public:

        graph(int v)
        {
            this->v=v;
        }        
        void addedge(int u,int v,int w)
        {
            edgelist.push_back({w,u,v});
        }
        int kruskal_mst()
        {
            sort(edgelist.begin(),edgelist.end());

            dsu s(v);
            int ans=0;

            for(auto edge:edgelist)
            {
                int w=edge[0];
                int x=edge[1];
                int y=edge[2];

                if(s.find(x)!=s.find(y))
                {
                    s.unite(x,y);
                    ans+=w;
                }
            }
            return ans;
        }
};

int main() 
{
    graph g(4);
    g.addedge(0,1,1);
    g.addedge(1,3,3);
    g.addedge(3,2,4);
    g.addedge(2,0,2);
    g.addedge(0,3,2);
    g.addedge(1,2,2);

    cout<<g.kruskal_mst();
}
