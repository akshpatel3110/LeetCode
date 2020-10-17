class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        vector<int> hour{8, 4, 2, 1}, min{32, 16, 8, 4, 2, 1};
        for (int cnt = 0; cnt <= num; ++cnt) {
            auto hours = get(hour, cnt);
            auto mins = get(min, num - cnt);
            for (int h : hours) {
                if (h <= 11) {
                    for (int m : mins) {
                        if (m <= 59)
                            res.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
                    }
                }
            }
        }
        return res;
    }
    
    vector<int> get(vector<int> & nums, int cnt) {
        vector<int> res;
        dfs(nums, cnt, 0, 0, res);
        return res;
    }
    
    void dfs(vector<int> & nums, int cnt, int u, int path, vector<int> & res) {
        if (cnt == 0) {
            res.push_back(path);
            return;
        }
        
        for (int i = u; i < nums.size(); ++i) {
            dfs(nums, cnt - 1, i + 1, path + nums[i], res);
        }
    }
};
