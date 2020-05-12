// Time: O(nlogn)
// space: O(n)
class MedianFinder {
    priority_queue<int> small; // Max heap
    priority_queue<int, vector<int>, greater<int>> large; // Min heap

public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {   
        if (small.empty() || num < small.top()) {
           small.push(num);
        } else {
           large.push(num);
        }
        
        if (small.size() == large.size() + 2) {
            large.push(small.top());
            small.pop();
        } else if (small.size() + 2 == large.size()) {
            small.push(large.top());
            large.pop();            
        } 
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return small.empty()? 0: ((small.top() + (long long)large.top()) / 2.0);
        } else if (small.size() == large.size() + 1) {
            return small.top();
        } else {
            return large.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
