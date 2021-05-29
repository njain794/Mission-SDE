
class Solution {
public:
    vector<vector<string>> ans;
    
    bool isafe(int row,int col,vector<string> temp,int n)
    {
       for(int i=0;i<col;i++)
       {
           if(temp[row][i]=='Q')
           {
               return false;
           }
       }
       
        int a=row-1;
        int b=col-1;
        
        while(a>=0 and b>=0)
        {
            if(temp[a][b]=='Q')
            {
                return false;
            }
            a--;
            b--;
        }
        
        int c=row+1;
        int d=col-1;
        
        while(c<n and d>=0)
        {
            if(temp[c][d]=='Q')
            {
                return false;
            }
            c++;
            d--;
        }
        
        return true;
        
    }
    
    void solve(int col,int n,vector<string> &temp)
    {
        if(col==n)
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(isafe(i,col,temp,n))
            {
                temp[i][col]='Q';
                solve(col+1,n,temp);
                temp[i][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string>temp;
        
        string s;
        for(int i=0;i<n;i++)
        {
            s+='.';
        }
        for(int i=0;i<n;i++)
        {
            temp.push_back(s);
        }
        
        solve(0,n,temp);
        for(auto x:ans)
        {
            for(auto c:x)
            {
                reverse(c.begin(),c.end());
            }
            reverse(x.begin(),x.end());
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
