/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        dfs_s(root, res);
        return res;
    }
    
    void dfs_s(TreeNode * node, string & res) {
        if (!node) return; // no longer serialize nullptr in BST 
        res += to_string(node->val) + ' ';
        dfs_s(node->left, res);
        dfs_s(node->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> v;
        stringstream ssin(data);
        int x;
        while (ssin >> x) v.push_back(x);
        int i = 0;
        return dfs_d(v, i, INT_MIN, INT_MAX);
    }
    
    TreeNode * dfs_d(vector<int> & v, int & i, int minv, int maxv) {
        if (i == v.size() || v[i] < minv || v[i] > maxv) return nullptr;
        auto node = new TreeNode(v[i++]);
        node->left = dfs_d(v, i, minv, node->val);
        node->right = dfs_d(v, i, node->val + 1, maxv);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
