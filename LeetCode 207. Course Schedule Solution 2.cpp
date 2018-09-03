// topological sort O(V + E)

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> & prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i)
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
    
        unordered_set<int> visiting;
        vector<bool> visited(numCourses, false);
        for (int node = 0; node < numCourses; ++node)
            if (dfs(node, graph, visiting, visited))
                return false;

        return true;        
    }
    
    bool dfs(int node, const vector<vector<int>> & graph, unordered_set<int> & visiting, vector<bool> & visited)
    {
        if (visiting.find(node) != visiting.end())
            return true;

        if (visited[node])
            return false;
        
        visiting.insert(node);
        for(const int neigh : graph[node])
            if (dfs(neigh, graph, visiting, visited))
                return true;

        visiting.erase(node);
        visited[node] = true;
        return false;
    }
};
