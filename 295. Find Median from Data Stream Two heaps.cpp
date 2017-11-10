/*
Solution 1:
sorted vector
addNum o(logn + n) = o(n)
findMedian o(1)


Solution 2:
sorted list: o(n)
addNum o(n)
findMedian o(1)


Solution 3:
Two heaps: o(logn)
Max heap: Smaller half
Min heap: Larger half
Size diff <= 1 --> same size: average of the top elements of the two heaps. Total even
               --> different size: The top element of the heap with larger size. Total odd
               
addNum o(logn)             
    Push: o(logn)
    optional rebalance: O(logn)
findMedian o(1)


Solution 4:
Multiset o(logn)
Two pointer: l and r
Even size: l = nums.size() / 2, r = nums.size() / 2 + 1
Odd size: l = r = nums.size() / 2

addNum o(logn)             
    Insert: o(logn)
    Move pointers: o(logn)
findMedian o(1)

*/


class MedianFinder {
    priority_queue<int> firstQ; // Max heap
    priority_queue<int, vector<int>, greater<int> > secQ; // Min heap

    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {   
        
        if (firstQ.empty() || num < firstQ.top()) {
           firstQ.push(num);
        } else {
           secQ.push(num);
        }
        
        if (firstQ.size() == secQ.size() + 2) {
            secQ.push(firstQ.top());
            firstQ.pop();
        } else if (firstQ.size()  + 2 == secQ.size()) {
            firstQ.push(secQ.top());
            secQ.pop();            
        }
        
    }
    
    double findMedian() {
        if (firstQ.size() == secQ.size()) {
            return firstQ.empty()? 0: ((firstQ.top() + secQ.top()) / 2.0);
        } else if (firstQ.size() == secQ.size() + 1) {
            return firstQ.top();
        } else {
            return secQ.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
