class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q{{0}};
        unordered_set<int> visited{0};
        while (q.size()) {
            int t = q.front();
            q.pop();
            for (int neigh : rooms[t]) {
                if (visited.count(neigh))
                    continue;
                
                q.push(neigh);
                visited.insert(neigh);
            }
        }
        return visited.size() == rooms.size();
    }
};
