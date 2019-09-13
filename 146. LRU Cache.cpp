class LRUCache {
public:
    LRUCache(int capacity_) 
        : capacity(capacity_)
    {}
    
    int get(int key) {        
        const auto it = m.find(key);
        
        // Key does not exist in the map
        if (it == m.cend()) 
            return -1;
 
        // Move the key value pair to the front of the list
        l.splice(l.begin(), l, it->second);
        
        // first it->second is the iterator, ->second again to get the value
        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it = m.find(key);
        
        // Key exists
        if (it != m.cend()) {
            // Update value
            it->second->second = value;
            // Move the key value pair to the front of the list
            l.splice(l.begin(), l, it->second);
            return;
        }
        
        // Pair does not exists, insert it
        // If capacity is reached, we need to remove the oldest entry from both map and list
        if (l.size() == capacity) {
            m.erase(l.back().first); // That is why we need the key in the pair
            l.pop_back();
        }
        
        // Insert pair to the front of the list
        l.emplace_front(key, value);
        
        // Update map
        m[key] = l.begin();        
    }
    
private:
    unordered_map<int, list<pair<int,int>>::iterator> m;
    list<pair<int, int>> l;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
