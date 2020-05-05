class Solution {
public:
    // Time: O(E)
    // Space: O(V)
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms, 0, visited);
        return visited.size() == rooms.size();
    }
    
    void dfs(vector<vector<int>> & rooms, int cur, unordered_set<int> & visited) {
        if (visited.count(cur))
            return;
        
        visited.insert(cur);
        for (int neigh : rooms[cur])
            dfs(rooms, neigh, visited);
    }
};
