class Solution {
public:
    // Time: O(E)
    // Space: O(V)
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited{0};
        queue<int> q{{0}};
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int neigh : rooms[t]) {
                if (visited.count(neigh))
                    continue;
                
                visited.insert(neigh);
                q.push(neigh);
            }     
        }
        return visited.size() == rooms.size();
    }
};
