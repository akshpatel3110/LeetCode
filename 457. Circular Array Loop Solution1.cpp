class Solution {
public:
    // Time: O(n)
    // Space: O(n)
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            unordered_set<int> st; // current visited indexes
            int p = i, last_step = -1, dir = nums[i] > 0; // last_step is for detecting self cycle
            do {
                int q = ((p + nums[p]) % n + n) % n; // there are also negative numbers
                last_step = nums[p];
                visited[p] = true;
                st.insert(p);
                p = q;
            } while (p != i && !visited[p] && (dir ^ (nums[p] > 0) == 0));
            if (last_step % n && st.count(p)) return true;
        }
        return false;
    }
};
