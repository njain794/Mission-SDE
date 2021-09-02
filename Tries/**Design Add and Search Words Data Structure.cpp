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

class WordDictionary {
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
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new trienode('\0');
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
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
