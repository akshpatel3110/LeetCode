/*
Build an undirected graph between all pairs of intervals that overlap. 
Use dfs or bfs traversal to find the unions.

For each union, merge all of its intervals by constructing a new interval with start equal to the minimum start among them and end equal to the maximum end.

Why not use disjoint set?
You don’t need to answer the question of whether two intervals are in the same union or not. All we need is the ability to know all the intervals within a union.
Building disjoint set takes more time than simple dfs or bfs traversal.

n is the number of intervals
Build graph: O(n ^ 2) time
DFS or BFS traversal: O(V+E) = O(n + n ^ 2) = O(n ^ 2) time
Merge: O(n) time
Overall time: O(n ^ 2)
In the worst case, all intervals are mutually overlapping, so there will be an edge for every pair of intervals.
Space: O(n ^ 2)
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        // build graph
        size_t len = intervals.size();
        vector<vector<size_t>> graph(len);
        for (size_t i = 0; i < len; ++i) {
            for (size_t j = i + 1; j < len; ++j) {
                if (intervals[i].start <= intervals[j].end &&
                    intervals[j].start <= intervals[i].end) {
                    // undirected graph
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        // dfs traversal
        unordered_set<size_t> visited;
        vector<vector<size_t>> unions;
        unions.reserve(len);
        size_t num_unions = 0;
        for (size_t node_idx = 0; node_idx < len; ++node_idx) {
            if (visited.find(node_idx) == visited.end()) {
                ++num_unions;
                unions.resize(num_unions);
                dfs(graph, visited, unions, num_unions - 1, node_idx);
            }
        }
        unions.shrink_to_fit();
        
        // loop over each union and merge
        vector<Interval> res;
        for (size_t union_idx = 0; union_idx < num_unions; ++union_idx) {
            Interval interval(INT_MAX, 0);
            for (size_t node_idx : unions[union_idx]) {
                interval.start = min(interval.start, intervals[node_idx].start);
                interval.end = max(interval.end, intervals[node_idx].end);
            }
            res.push_back(interval);
        }
        return res;
    }
    
private:
    void dfs(const vector<vector<size_t>> & graph, 
             unordered_set<size_t> & visited,
             vector<vector<size_t>> & unions,
             size_t union_idx,
             size_t node_idx) {
        if (visited.find(node_idx) != visited.end())
            return;
        
        visited.insert(node_idx);
        
        // This line is want we add in addtion to normal dfs
        unions[union_idx].push_back(node_idx);
        for (int neigh_idx : graph[node_idx])
            dfs(graph, visited, unions, union_idx, neigh_idx);
    }
};
