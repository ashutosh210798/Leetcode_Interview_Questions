class LRUCache {
private:
    unordered_map<int, pair <int, list<int>::iterator  > > cache;
    list<int>LRU; //storing keys
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    void use(  unordered_map<int, pair <int, list<int>::iterator  > > ::iterator &itr)
    {
        LRU.erase(itr->second.second);
        LRU.push_front(itr->first);
        itr->second.second=LRU.begin();
        
    }
 
    int get(int key) {
        
        auto itr=cache.find(key);
        if(itr==cache.end())
        {
            return -1;
        }
        
        use(itr);
        return itr->second.first;

        
    }
    
    void put(int key, int value) {
           auto itr=cache.find(key);
        if(itr!=cache.end())
        {
            use(itr);
            cache[key]={value,LRU.begin()};
            return ;
        }
        
        if(capacity==cache.size())
        {
            cache.erase(LRU.back());
            LRU.pop_back();
        }
        
        
        LRU.push_front(key);
        cache[key]={value,LRU.begin()};
        return ;
        
 
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
