class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> res;
        
        // sort
        sort(people.begin(), people.end(),[](pair<int,int> p1, pair<int,int> p2){
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        });
        
        // insert
        for (const auto& p : people){
            res.insert(res.begin() + p.second, p);
        }
        return res;        
    }
};
