////****Not Submitted***/////
class Solution {
public:

    void expnbr(int x,int y,int d1,int d2,queue<pair<int,int>>&q,vector<bool>vis[],bool &flag,int n)
    {
        int cx[]={-1,-1,1,1,2,2,-2,-2};
        int cy[]={2,-2,2,-2,1,-1,1,-1};
        
        for(int i=0;i<8;i++)
        {
            if(x+cx[i]<0 or x+cx[i]>=n or y+cy[i]<0 or y+cy[i]>=n or vis[x+cx[i]][y+cy[i]])
            {
                continue;
            }
            if(x+cx[i]==d1 and y+cy[i]==d2)
            {
                flag=true;
                return;
            }
            q.push({x+cx[i],y+cy[i]});
            vis[x+cx[i]][y+cy[i]]=true;
        }
    }

	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n)
	{
	    int steps=0;
	    int s1=KnightPos[0]-1;
	    int s2=KnightPos[1]-1;
	    
	    int d1=TargetPos[0]-1;
	    int d2=TargetPos[1]-1;
	    
	    if(s1==d1 and s2==d2)
	    {
	        return 0;
	    }
	    queue<pair<int,int>>q;
	    vector<bool>vis[n];
	    for(int r=0;r<n;r++)
	    {
	        for(int c=0;c<n;c++)
	        {
	            vis[r].push_back(false);
	        }
	    }
	    q.push({s1,s2});
	    vis[s1][s2]=true;
	    int count=q.size();
	    bool flag=false;
	    
	    while(count>0)
	    {
	        steps++;
	        for(int i=0;i<n;i++)
	        {
    	        pair<int,int>p=q.front();
    	        q.pop();
    	        expnbr(p.first,p.second,d1,d2,q,vis,flag,n);
    	        
    	        if(flag)
    	        {
    	            return steps;
    	        }
    	        //steps++;
	        }
	        //steps++;
	        count=q.size();
	    }
	    return -1;
	    // Code here
	}
};
