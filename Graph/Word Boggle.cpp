class Solution
{
    bool dfsRec(
                    vector<vector<char>> &board, 
                    string word, 
                    vector<vector<bool>> &visited, 
                    int row, 
                    int col, 
                    int wordIndex
                )
    {
        if(wordIndex == word.size())
        {
            return true;
        }
        
        if(
                row >= 0 and row < board.size() and 
                col >= 0 and col < board[0].size() and 
                visited[row][col] == false and
                board[row][col] == word[wordIndex]
            )
        {
            visited[row][col] = true;
            
            if(
                    dfsRec(board, word, visited, row - 1, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row - 1, col + 0, wordIndex + 1) or
                    dfsRec(board, word, visited, row - 1, col + 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 0, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 0, col + 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col - 1, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col + 0, wordIndex + 1) or
                    dfsRec(board, word, visited, row + 1, col + 1, wordIndex + 1)
                )
                {
                    return true;
                }
            
            visited[row][col] = false;
        }
        
        return false;
    }
    
    bool findWords(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        int wordIndex = 0;
        
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(board[row][col] == word[wordIndex])
                {
                    if(dfsRec(board, word, visited, row, col, wordIndex) == true)
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    public:
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary) 
    {
        vector<string> res;
        
        for(auto x: dictionary)
        {
            if(findWords(board, x))
            {
                res.push_back(x);
            }
        }
        
        return res;
    }
};


/////////////////OR/////////////////

/*class Solution {
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
	
	vector<string> wordBoggle(vector<vector<char> >&mat, vector<string>& dict) 
	{
	    vector<string>ans;
	    
	    for(auto x:dict)
	    {
	        if(isWordExist(mat,x))
	        {
	            ans.push_back(x);
	        }
	    }
	    return ans;
	    // Code here
	}
};*/
