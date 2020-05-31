class KthLargest {
public:
    KthLargest(int k, vector<int>& nums)
        : K(k)
    {
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > K)
            q.pop();
        
        return q.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
