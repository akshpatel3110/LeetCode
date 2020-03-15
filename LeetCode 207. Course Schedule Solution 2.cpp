class Solution {
public:
    // Time: O(V + E) = O(n + n(n - 1)) = O(n ^ 2)
    // Space: O(V + E) = O(n ^ 2)
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto & p : prerequisites)
            graph[p[1]].push_back(p[0]);
    
        vector<bool> visiting(numCourses, false);
        vector<bool> visited(numCourses, false);
        for (int node = 0; node < numCourses; ++node)
            if (dfs(node, graph, visiting, visited))
                return false;

        return true;     
    }
    
    bool dfs(int node, const vector<vector<int>> & graph, vector<bool> & visiting, vector<bool> & visited) { 
        if (visiting[node])
            return true;

        if (visited[node])
            return false;
        
        visiting[node] = true;
        for (auto neigh : graph[node])
            if (dfs(neigh, graph, visiting, visited))
                return true;

        visiting[node] = false;
        visited[node] = true;
        return false;
    }
};
