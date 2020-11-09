#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int>*l;
    
    public:
    
        graph(int V)
        {
            this->V = V;
            l = new list<int>[V];
        }
        void addedge(int v1,int v2)
        {
            l[v1].push_back(v2);
            l[v2].push_back(v1);
        }
        void print()
        {
            for(int i=0;i<V;i++)
            {
                cout<<i;
                for(auto x:l[i])
                {
                    cout<<"-> "<<x;
                }
                cout<<"\n";
            }
        }
};
int main() 
{
    int n;
    cin>>n;
    while(n--)
    {
        int v,e;
        int v1,v2;
        cin>>v;
        cin>>e;
        graph g(v);
        for(int i=0;i<e;i++)
        {
            cin>>v1;
            cin>>v2;
            g.addedge(v1,v2);
        }
        g.print();
    }
	//code
	return 0;
}
