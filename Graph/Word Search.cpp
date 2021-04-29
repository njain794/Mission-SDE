class Solution {
public:

    bool solve(int ptr,int i,int j,vector<vector<char>> &mat,string word,vector<vector<int>> &vis,int n,int m)
    {
        if(i<0 or i>n-1 or j<0 or j>m-1)
        {
            return false;
        }
        else if(vis[i][j]==1)
        {
            return false;
        }
        else if(ptr==word.size())
        {
            return true;
        }
        if(word[ptr]==mat[i][j] and vis[i][j]==0)
        {
            ptr++;
            
            vis[i][j]=1;
            int b1=solve(ptr,i+1,j,mat,word,vis,n,m);
            int b2=solve(ptr,i-1,j,mat,word,vis,n,m);
            int b3=solve(ptr,i,j+1,mat,word,vis,n,m);
            int b4=solve(ptr,i,j-1,mat,word,vis,n,m);
            
            vis[i][j]=0;
            if(b1 or b2 or b3 or b4)
            {
                return true;
            }
        
        }
        return false;
    }


    bool isWordExist(vector<vector<char>>& mat, string word) 
    {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        bool flag=false;
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==mat[i][j])
                {
                    flag=solve(0,i,j,mat,word,vis,n,m);
                    if(flag==true)
                    {
                        return true;
                    }
                }
            }
        }
        return flag;
        // Code here
    }
};
