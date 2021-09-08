class trienode{
    public:
    char data;
    unordered_map<char,trienode*>children;
    bool isterminal;
    
    trienode(char d)
    {
        data=d;
        isterminal=false;
    }
};

class Solution {
    trienode *root;
public:
    
    void insert(trienode* root,string s)
    {
        if(s.size()==0)
        {
            root->isterminal=true;
            return;
        }
        
        trienode *child;
        if(root->children.find(s[0])!=root->children.end())
        {
            child=root->children[s[0]];
        }
        else
        {
            root->children[s[0]]=new trienode(s[0]);
            child=root->children[s[0]];
        }
        insert(child,s.substr(1));
    }
    
    bool search(trienode *root,string s)
    {
        if(s.size()==0)
        {
            if(root->isterminal==true)
            {
                return true;
            }
            return false;
        }
        
        trienode *child;
        if(root->children.find(s[0])!=root->children.end())
        {
            child=root->children[s[0]];
            return search(child,s.substr(1));
        }
        return false;
        
    }
    
    bool solve(trienode* root,string s)
    {
        if(s.size()==0)
        {
            return true;
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(search(root,s.substr(0,i+1)) and solve(root,s.substr(i+1)))
            {
                return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        root=new trienode('\0');
        for(auto word:wordDict)
        {
            insert(root,word);
        }
        
        return solve(root,s);
    }
};
