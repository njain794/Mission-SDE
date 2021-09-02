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

class Trie {
    trienode *root;
    
    void insertword(trienode *root,string word)
    {
        if(word.length()==0)
        {
            root->isterminal=true;
            return;
        }
        trienode* child;
        if(root->children.find(word[0])!=root->children.end())
        {
            child=root->children[word[0]];
        }
        else
        {
            root->children[word[0]]=new trienode(word[0]);
            child=root->children[word[0]];
        }
        insertword(child,word.substr(1));
    }
    
    int searchword(trienode *root,string word)
    {
        if(word.length()==0)
        {
            if(root->isterminal)
            {
                return 1;
            }
            return 0;
        }
        trienode *child;
        if(root->children.find(word[0])!=root->children.end())
        {
            child=root->children[word[0]];
            return searchword(child,word.substr(1));
        }
        return -1;
    }
    
    
public: 
    /** Initialize your data structure here. */
    Trie() {
        root=new trienode('\0');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        insertword(root,word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(searchword(root,word)==1)
        {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        if(searchword(root,prefix)>=0)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
