class treenode{
  public:
    char data;
    unordered_map<char,treenode*>children;
    bool isterminal;
    
    treenode(char ch)
    {
        data=ch;
        isterminal=false;
    }
};

class Solution {
public:
    
    void insert(treenode *root,string s)
    {
        if(s.size()==0)
        {
            root->isterminal=true;
            return;
        }
        
        treenode *child;
        if(root->children.find(s[0])!=root->children.end())
        {
            child=root->children[s[0]];
        }
        else
        {
            root->children[s[0]]=new treenode(s[0]);
            child=root->children[s[0]];
        }
        insert(child,s.substr(1));        
    }
    
    bool check(treenode *root,string s)
    {
        treenode *temp=root;
        for(int i=0;i<s.size();i++)
        {
            if(temp->children.find(s[i])==temp->children.end())
            {
                return false;
            }
            temp=temp->children[s[i]];
            if(temp->isterminal==false)
            {
                return false;
            }
        }
        return true;
    }
    
    
    string longestWord(vector<string>& words) 
    {
        sort(words.begin(),words.end());
        treenode *root=new treenode('\0');
        
        string ans="";
        if(words[0].size()==1)
        {
            ans=words[0];
        }
        
        insert(root,words[0]);
        int n=words.size();
        for(int i=1;i<n;i++)
        {
            if(words[i].size()>1 and check(root,words[i].substr(0,words[i].size()-1)))
            {
                if(words[i].size()>ans.size())
                {
                    ans=words[i];
                }
                else if(words[i].size()==ans.size())
                {
                    ans=min(ans,words[i]);
                }
            }
            insert(root,words[i]);
        }
        return ans;
    }
};
