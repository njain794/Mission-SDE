//https://practice.geeksforgeeks.org/viewSol.php?subId=10f54f13cf7dbc85be2fa4a360948479&pid=705651&user=namanjain41

class Solution {
public:
    int n, m;
    int dx[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int dy[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int> > ans;
	   int n = grid.size();
	   int m = grid[0].size();
	   
	   int len = word.size();
	   
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       {
	           if(grid[i][j] == word[0])
	           {
	               int x = i, y = j;
	               for(int dir=0;dir<8;dir++)
	               {
	                   int xx = x, yy = y, k;
	                   for(k = 0;k<len;k++)
	                   {
	                       if( (xx>=0) && (yy>=0) && (xx<n) && (yy<m) && (grid[xx][yy]==word[k]) )
	                       {
	                           xx += dx[dir];
	                           yy += dy[dir];
	                       }
	                       else break;
	                   }
	                   if(k == len)
	                   {
	                       ans.push_back({i, j});
	                       break;
	                   }
	               }
	           }
	       }
	   }
	   if(ans.size() == 0)
	        ans.push_back({-1});
	   return ans;
	}
};
