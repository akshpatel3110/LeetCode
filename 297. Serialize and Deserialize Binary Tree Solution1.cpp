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
        s_dfs(root, res);
        return res;
    }
    
    void s_dfs(TreeNode * node, string & res) {
        if (!node) {
            res += ',';
            return;
        }
        
        res += to_string(node->val) + ',';
        s_dfs(node->left, res);
        s_dfs(node->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return d_dfs(data, i);
    }
    
    TreeNode * d_dfs(const string & data, int & i) {
        if (data[i] == ',') {
            ++i;
            return nullptr;
        }
        
        int j = i;
        while (data[j] != ',')
            ++j;
        
        auto node = new TreeNode(stoi(data.substr(i, j - i)));
        i = j + 1;
        node->left = d_dfs(data, i);
        node->right = d_dfs(data, i);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
