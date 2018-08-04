/*

Time: O(V + E) 1000 + 3000
Space: O(V) 1000

*/


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms, visited, 0);
        return visited.size() == rooms.size();
    }
    
private:
    void dfs(vector<vector<int>>& rooms, unordered_set<int> & visited, int cur) {
        if (visited.find(cur) != visited.end())
            return;
        
        visited.insert(cur);
        for (int neigh : rooms[cur])
            dfs(rooms, visited, neigh);
    }
};
