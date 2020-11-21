struct Node {
    int key;
    int value; // can be put to value of hash_freq
    int freq;  // can be put to value of hash_freq
    list<int>::const_iterator it;
};

class LFUCache {
public:
    int cap;
    int min_freq;
    unordered_map<int, Node> hash_node;
    unordered_map<int, list<int>> hash_freq;

    LFUCache(int capacity) 
        : cap(capacity)
        , min_freq(0)
    {}
    
    void touch(Node & node) {
        // old freq
        auto & old_l = hash_freq[node.freq];
        old_l.erase(node.it);
        if (old_l.empty()) {
            hash_freq.erase(node.freq);
            if (node.freq == min_freq)
                ++min_freq;
        }
        
        // new freq
        ++node.freq;
        auto & new_l = hash_freq[node.freq]; // create new_l if it does not exist
        new_l.push_front(node.key);
        node.it = new_l.begin();
    }
    
    int get(int key) {
        auto it = hash_node.find(key);
        if (it == hash_node.end()) return -1;
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        auto it = hash_node.find(key);
        if (it != hash_node.end()) {
            it->second.value = value;
            touch(it->second);
            return;
        }
        
        if (hash_node.size() == cap) {
            auto & l = hash_freq[min_freq];
            hash_node.erase(l.back());
            l.pop_back();
            
            // no need to update min_freq because the new item has freq of 1
            if (l.empty()) hash_freq.erase(min_freq);
        }
        min_freq = 1;
        hash_freq[1].push_front(key);
        hash_node[key] = {key, value, 1, hash_freq[1].begin()};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
