class AllOne {
    unordered_map<string,int>keys;
    map<int,unordered_set<string>>freq;
public:
    /** Initialize your data structure here. */
    AllOne() {
        keys.clear();
        freq.clear();
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) 
    {
        keys[key]++;
        int cnt=keys[key];
        freq[cnt].insert(key);
        if(cnt>1)
        {
            freq[cnt-1].erase(key);
            if(freq[cnt-1].empty())
            {
                freq.erase(cnt-1);
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) 
    {
        keys[key]--;
        int cnt=keys[key];
        freq[cnt+1].erase(key);
        if(cnt<=0)
        {
            keys.erase(key);
        }
        else
        {
            freq[cnt].insert(key);
        }
        if(freq[cnt+1].empty())
        {
            freq.erase(cnt+1);
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() 
    {
        if(freq.size()==0)
        {
            return "";
        }
        auto it=freq.end();
        --it;
        return *it->second.begin();
        
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() 
    {
        if(freq.size()==0)
        {
            return "";
        }
        auto it=freq.begin();
        return *it->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
