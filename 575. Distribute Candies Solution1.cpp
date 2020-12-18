class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for (auto c : candyType)
            st.insert(c);
        return min(candyType.size() / 2, st.size());
    }
};
