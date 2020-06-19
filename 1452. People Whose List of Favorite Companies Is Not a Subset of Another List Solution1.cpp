class Solution {
public:
    bool is_subset(vector<string> & l1, vector<string> & l2) {
        int m = l1.size(), n = l2.size();
        if (m > n)
            return false;
        
        for (int i = 0, j = 0; j < n; ++j)
            if (l1[i] == l2[j]) {
                ++i;
                if (i == m)
                    return true;
            }
        return false;
    }
    
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        for (auto & l : favoriteCompanies)
            sort(l.begin(), l.end());
        
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            bool flag = false;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    auto & l1 = favoriteCompanies[i], & l2 = favoriteCompanies[j];
                    if (is_subset(l1, l2)) {
                        flag = true;
                        break;
                    } 
                }
            }
            if (!flag) {
                res.push_back(i);
            }
        }
        return res;
    }
};
