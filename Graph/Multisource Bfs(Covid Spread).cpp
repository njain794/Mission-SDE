//https://practice.geeksforgeeks.org/problems/269f61832b146dd5e6d89b4ca18cbd2a2654ebbe/1#


class Solution {
public:

    bool check(int x,int y,int n,int m,vector<vector<int>> &mat)
    {
        if(x>=0 and x<n and y>=0 and y<m and mat[x][y]==1)
        {
            return true;
        }
        return false;
    }

    int helpaterp(vector<vector<int>> mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        int cnt=0;
        
        while(!q.empty())
        {
            int x=q.size();
            while(x--)
            {
                auto p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                
                if(check(x-1,y,n,m,mat))
                {
                    q.push({x-1,y});
                    mat[x-1][y]=2;
                }
                if(check(x+1,y,n,m,mat))
                {
                    q.push({x+1,y});
                    mat[x+1][y]=2;
                }
                if(check(x,y-1,n,m,mat))
                {
                    q.push({x,y-1});
                    mat[x][y-1]=2;
                }
                if(check(x,y+1,n,m,mat))
                {
                    q.push({x,y+1});
                    mat[x][y+1]=2;
                }
                //q.pop();
            }
            cnt++;
        }
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]==1)
                    {
                        return -1;
                        //q.push({i,j});
                    }
                }
            }
        return cnt-1;
        //code here
    }
};
