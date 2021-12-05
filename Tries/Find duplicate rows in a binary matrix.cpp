// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class trienode{
    public:
    char data;
    unordered_map<char,trienode*>children;
    bool isterminal;
    
    trienode(char ch)
    {
        data=ch;
        isterminal=false;
    }
};
class Solution
{   
    trienode *root;
    
    void insert(trienode *root,string word)
    {
        if(word.length()==0)
        {
            root->isterminal=true;
            return;
        }
        trienode *child;
        if(root->children.find(word[0])!=root->children.end())
        {
            child=root->children[word[0]];
        }
        else
        {
            root->children[word[0]]=new trienode(word[0]);
            child=root->children[word[0]];
        }
        insert(child,word.substr(1));
    }
    
    int searchword(trienode *root,string word,bool &found)
    {
        if(word.length()==0)
        {
            if(root->isterminal)
            {
                found=true;
                return 1;
            }
            return 0;
        }
        trienode *child;
        if(word[0]=='.')
        {
            trienode *temp;
           for(auto x:root->children) 
           {
               char ch=x.first;
               temp=root->children[ch];
               if(searchword(temp,word.substr(1),found)>=1)
               {
                   return 1;
               }
           }
        }
        
        else if(root->children.find(word[0])!=root->children.end())
        {
            child=root->children[word[0]];
            return searchword(child,word.substr(1),found);
        }
        return -1;
    }
    
    void addWord(string word) 
    {
        insert(root,word);   
    }
    
    bool search(string word) {
        /*if(searchword(root,word)>=1)
        {
            return true;
        }*/
        bool flag=false;
        searchword(root,word,flag);
        return flag;
    }
    
    public:
        vector<int> repeatedRows(vector<vector<int>> mat, int n, int m) 
        { 
            root=new trienode('\0');
            vector<string> temp;
            vector<int>ans;
            
            for(int i=0;i<n;i++)
            {
                string tmp;
                for(int j=0;j<m;j++)
                {
                    tmp.push_back(mat[i][j]+'0');
                }
                temp.push_back(tmp);
                tmp.clear();
            }
            
            int d=temp.size();
            
            for(int i=0;i<d;i++)
            {
                if(search(temp[i]))
                {
                    ans.push_back(i);
                }
                else
                {
                    addWord(temp[i]);
                }
            }
            
            return ans;
        } 
};


// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


  // } Driver Code Ends
