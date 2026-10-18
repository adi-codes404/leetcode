class LRUCache {
private:
    int capacity;
    
    // Stores key -> iterator to its position in the list
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        
        if (it == mp.end()) {
            return -1;
        }
        
        // Move the accessed element to the front (most recently used)
        cache.splice(cache.begin(), cache, it->second);
        
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        
        if (it != mp.end()) {
            // Update the existing value and mark it recently used
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        
        // Evict the least recently used element if full
        if (cache.size() == capacity) {
            int lruKey = cache.back().first;
            cache.pop_back();
            mp.erase(lruKey);
        }
        
        // Insert the new element at the front
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */