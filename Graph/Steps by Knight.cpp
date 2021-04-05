class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n)
	{
	    int x1=KnightPos[0];
	    int y1=KnightPos[1];
	    
	    int x2=TargetPos[0];
	    int y2=TargetPos[1];
	    
	    if(x1==x2 and y1==y2)
	    {
	        return 0;
	    }
	    
	    int mat[1001][1001];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            mat[i][j]=0;
	        }
	    }
	    
	    queue<pair<int,int>>q;
	    q.push({x1-1,y1-1});
	    while(!q.empty())
	    {
	        auto curr=q.front();
	        int i=curr.first;
	        int j=curr.second;
	        q.pop();
	        
	        if(i-2>=0 and i-2<n and j+1>=0 and j+1<n and mat[i-2][j+1]==0)
	        {
	            mat[i-2][j+1]=mat[i][j]+1;
	            q.push({i-2,j+1});
	        }
	        if(i-2>=0 and i-2<n and j-1>=0 and j-1<n and mat[i-2][j-1]==0)
	        {
	            mat[i-2][j-1]=mat[i][j]+1;
	            q.push({i-2,j-1});
	        }
	        if(i+2>=0 and i+2<n and j+1>=0 and j+1<n and mat[i+2][j+1]==0)
	        {
	            mat[i+2][j+1]=mat[i][j]+1;
	            q.push({i+2,j+1});
	        }
	        if(i+2>=0 and i+2<n and j-1>=0 and j-1<n and mat[i+2][j-1]==0)
	        {
	            mat[i+2][j-1]=mat[i][j]+1;
	            q.push({i+2,j-1});
	        }
	        if(i-1>=0 and i-1<n and j+2>=0 and j+2<n and mat[i-1][j+2]==0)
	        {
	            mat[i-1][j+2]=mat[i][j]+1;
	            q.push({i-1,j+2});
	        }
	        if(i-1>=0 and i-1<n and j-2>=0 and j-2<n and mat[i-1][j-2]==0)
	        {
	            mat[i-1][j-2]=mat[i][j]+1;
	            q.push({i-1,j-2});
	        }
	        if(i+1>=0 and i+1<n and j+2>=0 and j+2<n and mat[i+1][j+2]==0)
	        {
	            mat[i+1][j+2]=mat[i][j]+1;
	            q.push({i+1,j+2});
	        }
	        if(i+1>=0 and i+1<n and j-2>=0 and j-2<n and mat[i+1][j-2]==0)
	        {
	            mat[i+1][j-2]=mat[i][j]+1;
	            q.push({i+1,j-2});
	        }
	    }
	    
	    return mat[x2-1][y2-1];
	    // Code here
	}
};
