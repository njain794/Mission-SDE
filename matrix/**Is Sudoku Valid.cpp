// https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1#

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int row[9][9];
    int col[9][9];
    int block[9];

    bool isvalid(vector<vector<int>> mat,int i,int j)
    {
        memset(block,0,sizeof(block));
        
        int n=i+2;
        int m=j+2;
        
        while(i<=n)
        {
            while(j<=m)
            {
                if(mat[i][j]!=0)
                {
                    int curr=mat[i][j]-1;
                    if(row[i][curr] or col[j][curr] or block[curr])
                    {
                        return false;
                    }
                    row[i][curr]=col[j][curr]=block[curr]=1;
                }
                j++;
            }
            j-=3;
            i++;
        }
        
        return true;
        
    }

    int isValid(vector<vector<int>> mat)
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(int i=0;i<=6;i+=3)
        {
            for(int j=0;j<=6;j+=3)
            {
                if(!isvalid(mat,i,j))
                {
                    return false;
                }
            }
        }
        return true;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
