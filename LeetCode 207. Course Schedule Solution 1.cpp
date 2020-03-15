class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (const auto & p : prerequisites)
            graph[p[1]].push_back(p[0]);
    
        for (int node = 0; node < numCourses; ++node) {
            vector<bool> visited(numCourses, false);
            if (dfs(node, node, graph, visited))
                return false;
        }

        return true;
    }
    
    bool dfs(int start,
             int cur,
             const vector<vector<int>> & graph,
             vector<bool> & visited) {
        if (start == cur && visited[start])
            return true;
        
        if (visited[cur])
            return false;
        
        visited[cur] = true;
        for (const int neigh : graph[cur]) {
            if (dfs(start, neigh, graph, visited))
                return true;
        }
        
        return false;
    }
    
    
};
