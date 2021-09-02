class MagicDictionary {
    unordered_map<int,vector<string>>mp;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        mp.clear();
    }
    
    void buildDict(vector<string> dict) 
    {
        for(auto x:dict)
        {
            mp[x.size()].push_back(x);
        }
    }
    
    bool search(string word) 
    {
        int len = word.size();
        for(auto w:mp[len])
        {
            int cnt=0;
            for(int i=0;i<w.size();i++)
            {
                if(word[i]!=w[i])
                {
                    cnt++;
                }
                if(cnt>1)
                {
                    break;
                }
            }
            if(cnt==1)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
