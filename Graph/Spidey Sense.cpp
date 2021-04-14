// https://practice.geeksforgeeks.org/problems/spidey-sense5556/1/?track=30-DOC-day-25&batchId=320#
class Solution{

    public:
    
    void bfs(vector<vector<char>>& mat,vector<vector<int>> &ans,int i,int j,int m,int n)
    {
        queue<pair<int,int>>q;
        ans[i][j]=0;
        
        int idxi[]={-1,0,1,0};
        int idxj[]={0,-1,0,1};
        q.push({i,j});
        
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int r=curr.first;
            int c=curr.second;
            
            for(int k=0;k<4;k++)
            {
                if(r+idxi[k]>=0 and r+idxi[k]<m and c+idxj[k]>=0 and c+idxj[k]<n)
                {
                    int row=r+idxi[k];
                    int col=c+idxj[k];
                    
                    if(1+ans[r][c]<ans[row][col] and mat[row][col]!='W')
                    {
                        ans[row][col]=1+ans[r][c];
                        q.push({row,col});
                    }
                    //ans[row][col]=min(1+ans[r][c],ans[row][col]);
                }
            }
        }
    }
    
    vector<vector<int> > findDistance(vector<vector<char> >& mat, int m, int n) 
    { 
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]=='B')
                {
                    bfs(mat,ans,i,j,m,n);
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ans[i][j]==INT_MAX)
                {
                    ans[i][j]=-1;
                }
            }
        }
        
        return ans;
        // Your code goes here
    } 
};
