
class Solution{
public:
bool isSafe(int row, int col, vector<vector<int>> &board){
    for(int i=0; i<col; i++)
        if(board[row][i] == 1)
            return false;
    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j] == 1)
            return false;
    for(int i=row, j=col; i<board.size() && j>=0; i++, j--)
        if(board[i][j] == 1)
            return false;
    return true;
}

bool mcQueen(int col, int n, vector<vector<int>> &board, vector<vector<int>> &res){
    if(col == n) {
        vector<int> v;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(board[i][j])
                    v.push_back(j+1);
        res.push_back(v);
        return true;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board)){
            board[row][col] = 1;
            mcQueen(col+1, n, board, res);
            board[row][col] = 0;
        }
    }
    return false;
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> board(n, vector<int> (n, 0));
    vector<vector<int>> res;
    mcQueen(0, n, board, res);
    sort(res.begin(), res.end());
    return res;
}
    
};

///////////////////////////// or ///////////////////////////

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
