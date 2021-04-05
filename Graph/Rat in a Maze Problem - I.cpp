class Solution{
    public:
    
    void solve(vector<vector<int>> &m,int i,int j,int n,vector<vector<int>> &vis,string ans,vector<string>&res)
    {
        if(i>n-1 or j>n-1 or i<0 or j<0)
        {
            return;
        }
        else if(m[i][j]==0 or vis[i][j]==1)
        {
            return;
        }
        else if(i==n-1 and j==n-1)
        {
            res.push_back(ans);
        }
        
        vis[i][j]=1;
        solve(m,i-1,j,n,vis,ans+'U',res);
        solve(m,i+1,j,n,vis,ans+'D',res);
        solve(m,i,j-1,n,vis,ans+'L',res);
        solve(m,i,j+1,n,vis,ans+'R',res);
        vis[i][j]=0;
    }    
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        vector<vector<int>>vis(n,vector<int>(n,0));
        string ans="";
        vector<string>res;
        solve(m,0,0,n,vis,ans,res);
        sort(res.begin(),res.end());
        return res;
        // Your code goes here
    }
};

//////////////////////////  OR  ////////////////////////

bool path(int mat[MAX][MAX],int i,int j,int n,int m,string res,vector<string>&ans)
{
    if(i>n or j>m or i<0 or j<0)
    {
        return false;
    }
    if(mat[i][j]!=1)
    {
        return false;
    }
    if(i==n and j==m)
    {
        ans.push_back(res);
        return true;
    }
    mat[i][j]=-1;
    //bool up=path(mat,i-1,j,n,m,res,ans);
    bool down=path(mat,i+1,j,n,m,res+'D',ans);
    bool left=path(mat,i,j-1,n,m,res+'L',ans);
    bool right=path(mat,i,j+1,n,m,res+'R',ans);
    bool up=path(mat,i-1,j,n,m,res+'U',ans);
    
    mat[i][j]=1;
    if(up or down or left or right)
    {
        return true;
    }
    else
    {
        return false;
    }
}
vector<string> printPath(int m[MAX][MAX], int n) 
{
    vector<string>ans;
    vector<string>emp;
    string res;
    int i=0,j=0;
    bool sol=path(m,i,j,n-1,n-1,res,ans);
    if(sol==false)
    {
       return emp; 
    }
    else
    {
        //ans.push_back(res);
        return ans;
    }
    // Your code goes here
}


