// brute force O(VE)

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> & prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(int i = 0; i < prerequisites.size(); ++i)
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
    
        for(int node = 0; node < numCourses; ++node) {
            vector<bool> visited(numCourses, false);
            if (cycle(node, node, graph, visited))
                return false;
        }

        return true;    
    }
    
    bool cycle(int start, 
               int cur,
               const vector<vector<int>> & graph,
               vector<bool> & visited) {
        if (start == cur && visited[start])
            return true;
        
        if (visited[cur])
            return false;
        
        visited[cur] = true;
        for (const int neigh : graph[cur]) {
            if (cycle(start, neigh, graph, visited))
                return true;
        }
        
        return false;
    }
};
