
/// Shortest path in a weighted graph from source to destination////////////////////

#include<bits/stdc++.h>
using namespace std;

#define ppi pair<int,pair<int,string>>

void solve(vector<vector<int>>&mat,int n)
{
	vector<bool>vis(n,false);

	priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
…				cin>>e;
				mat[i][j]=e;
			}
		}

		solve(mat,n);
		cout<<"\n";
	}
}
