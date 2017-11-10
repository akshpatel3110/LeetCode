/*
time O(n ^ 2)
sort O(nlogn)
insertion O(n ^ 2)

space O(n)

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

sort:
[[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]

Base case:
[7, 0] is inserted to the first position.


*/

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int n = people.size();
        if (n == 0)
            return {};
        
        sort(people.begin(), people.end(), [](pair<int,int> p1, pair<int,int> p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        
        vector<pair<int,int>> res;
        dfs(people.size() - 1, res, people);
        return res;        
    }
    
    void dfs(int index, vector<pair<int,int>>& res, const vector<pair<int, int>>& people) {
        const auto& p = people[index];

        if (index == 0) {
            res.push_back(p);
            return;
        }

        dfs(index - 1, res, people);
        res.insert(res.begin() + p.second, p);
    }
};
