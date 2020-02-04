class MaxHeap {
    vector<int> index;
    vector<pair<int, int>> values;
    int size;
    
    void swapNode(int index1, int index2) {
        swap(index[values[index1].second], index[values[index2].second]);
        swap(values[index1], values[index2]);
    }
    
    void heapifyUp(int idx) {
        while (idx != 0) {
            int parent = (idx - 1) / 2;
            if (values[idx].first <= values[parent].first)
                return;
            
            swapNode(idx, parent);
            idx = parent;
        }
    }
    
    void heapifyDown(int idx) {
        while (true) {
            int l = idx * 2 + 1;
            int r = idx * 2 + 2;
            
            int largest = idx;
            
            if (l < size && values[l].first > values[idx].first)
                largest = l;
            
            if (r < size && values[r].first > values[largest].first)
                largest = r;
            
            if (largest == idx)
                return;
            
            swapNode(largest, idx);
            idx = largest;
        }
    }
    
public:
    MaxHeap(int s): index(s), values(s), size(0) {}
    
    int max() const {
        return values[0].first;
    }
    
    void insert(int height, int id) {
        index[id] = size;
        values[size] = {height, id};
        ++size;
        heapifyUp(index[id]);
    }
    
    void remove(int id) {
        int indexRemove = index[id];
        swapNode(indexRemove, size - 1);
        --size;
        heapifyUp(indexRemove);
        heapifyDown(indexRemove);
    }
};

class Solution {
public:
    // Time: O(nlogn)
    // Space: O(n)
    // entering and leaving point with same x, process entering point first -> set entering point to a negative value
    // entering point with same x, process the highest point first -> set entering point to a negative value
    // leaving point with same x, process the lowest point first -> set leaving point to a positive value
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<Point> points;
        for (int i = 0; i < buildings.size(); ++i) {
            const auto & b = buildings[i];
            points.push_back(Point{i + 1, b[0], -b[2]});
            points.push_back(Point{i + 1, b[1], b[2]});
        }
        sort(points.begin(), points.end());
        MaxHeap heap(buildings.size() + 1); // plus one for the zero
        heap.insert(0, 0); // height 0, id 0
        int pre = 0, cur = 0;
        for (auto & p : points) {
            if (p.h < 0) {
                heap.insert(-p.h, p.id);
            } else {
                heap.remove(p.id);
            }
            cur = heap.max();
            if (cur != pre) {
                res.push_back({p.x, cur});
                pre = cur;
            }
        }
        return res;
    }
    
private:
    struct Point {
        int id;
        int x;
        int h;

        bool operator<(const Point & rhs) const {
            if (x == rhs.x) {
                return h < rhs.h;
            }
            return x < rhs.x;
        }
    };
};
