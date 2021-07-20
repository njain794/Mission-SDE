class LRUCache {
public:
    
    int sz;
    list<pair<int,int>>keys;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    
    LRUCache(int capacity) {
        sz=capacity;
        keys.clear();
        mp.clear();
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            auto itr=mp[key];
            int value=itr->second;
            
            keys.erase(itr);
            keys.push_front({key,value});
            mp[key]=keys.begin();
            return value;
        }
        else
        {
            return -1;
        }
        
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)==mp.end())
        {
            if(keys.size()==sz)
            {
                auto itr=keys.back();
                mp.erase(itr.first);
                keys.pop_back();
            }
        }
        else
        {
            keys.erase(mp[key]);
        }
        keys.push_front({key,value});
        mp[key]=keys.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
