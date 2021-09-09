class LFUCache {
    unordered_map<int,pair<int,int>>keyval;
    unordered_map<int,list<int>>cache;
    unordered_map<int,list<int>::iterator>keynode;
    int c;
    int lfu;
public:
    LFUCache(int capacity) 
    {
        keyval.clear();
        keynode.clear();
        cache.clear();
        c=capacity;
        //lfu;
    }
    
    int get(int key) 
    {
        if(c==0)
        {
            return -1;
        }
        if(keyval.find(key)==keyval.end())
        {
            return -1;
        }
        
        keyval[key].second++;
        int f=keyval[key].second;
        
        cache[f-1].erase(keynode[key]);
        if(cache[f-1].empty())
        {
            cache.erase(f-1);
        }
        keynode.erase(key);
        
        if(lfu==f-1 and cache.find(f-1)==cache.end())
        {
            lfu=f;
        }
        
        cache[f].push_back(key);
        keynode[key]=(--cache[f].end());
        return keyval[key].first;
    }
    
    void put(int key, int value) 
    {
       if(c==0)
       {
           return;
       }
       if(keyval.find(key)!=keyval.end())
       {
           keyval[key].first=value;
           keyval[key].second++;
           
           int f=keyval[key].second;
           cache[f-1].erase(keynode[key]);
           if(cache[f-1].empty())
           {
               cache.erase(f-1);
           }
           keynode.erase(key);
           
           if(lfu==f-1 and cache.find(f-1)==cache.end())
           {
               lfu=f;
           }
           
           cache[f].push_back(key);
           keynode[key]=(--cache[f].end());
       }
       else
       {
           if(keyval.size()==c)
           {
               int del=cache[lfu].front();
               cache[lfu].pop_front();
               if(cache[lfu].empty())
               {
                   cache.erase(lfu);
               }
               keyval.erase(key);
               keynode.erase(key);
           }
           
           keyval[key]={value,1};
           cache[1].push_back(key);
           keynode[key]=(--cache[1].end());
           lfu=1;
       } 
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
