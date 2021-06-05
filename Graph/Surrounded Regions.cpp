class Solution {
public:
    
    void change(vector<vector<char>>& board,int i,int j,int n,int m)
    {
        if(i<0 or i>=n or j<0 or j>=m or board[i][j]!='O')
        {
            return;
        }
        board[i][j]='#';
        change(board,i+1,j,n,m);
        change(board,i-1,j,n,m);
        change(board,i,j+1,n,m);
        change(board,i,j-1,n,m);
    }
    
    void solve(vector<vector<char>>& board) 
    {
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0 or i==n-1 or j==m-1 and board[i][j]=='O')
                {
                    change(board,i,j,n,m);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};
