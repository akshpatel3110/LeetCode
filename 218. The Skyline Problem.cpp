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
        return size == 0 ? 0 : values[0].first;
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
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Point> points;
        
        for (int i = 0; i < buildings.size(); ++i) {
            points.push_back(Point{1, i, buildings[i][0], buildings[i][2]});
            points.push_back(Point{-1, i, buildings[i][1], buildings[i][2]});
        }
        
        sort(points.begin(), points.end());
        
        MaxHeap heap(buildings.size());
        vector<pair<int, int>> res;
        
        for (const auto& p: points) {
            if (p.enter == 1) {
                if (p.h > heap.max())
                    res.emplace_back(p.x, p.h);
                heap.insert(p.h, p.id);
            } else {
                heap.remove(p.id);
                if (p.h > heap.max())
                    res.emplace_back(p.x, heap.max());
            }
        }
        
        return res;
        
        
    }
    
private:
    struct Point {
        int enter;
        int id;
        int x;
        int h;
        
        bool operator<(const Point& rhs) const {
            if (x == rhs.x) {
                return enter * h > rhs.enter * rhs.h;
            }
            return x < rhs.x;
        }
    };
};
