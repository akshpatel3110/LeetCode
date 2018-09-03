// O(V + E)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto & pre : prerequisites)
            graph[pre.second].push_back(pre.first);
    
        unordered_set<int> visiting;
        vector<bool> visited(numCourses, false);
        vector<int> res;
        for (int node = 0; node < numCourses; ++node)
            if (!visited[node] && dfs(node, graph, visiting, visited, res))
                return {};

        reverse(res.begin(), res.end());
        return res;        
    }
    
    bool dfs(int node, 
             const vector<vector<int>> & graph, 
             unordered_set<int> & visiting, 
             vector<bool> & visited,
             vector<int> & res)
    {
        if (visiting.find(node) != visiting.end())
            return true;

        if (visited[node])
            return false;
        
        visiting.insert(node);
        for(const int neigh : graph[node])
            if (dfs(neigh, graph, visiting, visited, res))
                return true;

        visiting.erase(node);
        visited[node] = true;
        res.push_back(node);
        return false;
    }
};
