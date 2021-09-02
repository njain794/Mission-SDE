class LRUCache {
public:
    unordered_map<int,list<pair<int, int>>::iterator>mp;
    list<pair<int,int>>cache;
    int cap;
    LRUCache(int capacity) 
    {
        mp.clear();
        cache.clear();
        cap=capacity;
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            auto idx=mp[key];
            int val=idx->second;
            cache.erase(idx);
            cache.push_front(make_pair(key,val));
            mp[key]=cache.begin();
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            cache.erase(mp[key]);
            cache.push_front({key,value});
            mp[key]=cache.begin();
            return;
        }
        else if(cache.size()==cap)
        {
            mp.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key,value});
        mp[key]=cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
