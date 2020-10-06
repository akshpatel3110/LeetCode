class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> hash;
    
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int x) {
        bool res = hash[x].empty();
        nums.push_back(x);
        hash[x].insert(nums.size() - 1);
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int x) {
        if (hash[x].size()) {
            int y = nums.back();
            int px = *hash[x].begin(), py = nums.size() - 1;
            swap(nums[px], nums[py]);
            hash[x].erase(px), hash[y].insert(py);
            hash[y].erase(py), hash[y].insert(px);
            nums.pop_back();
            hash[x].erase(py);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
