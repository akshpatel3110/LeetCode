/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 
 
                 1 -> nullptr
               /  \
 parent       2 -> 3 -> nullptr
             / \    \
            4 ->5 -> 7
    childHead   
                   child
       
 */
class Solution {
public:
    void connect(TreeLinkNode *parent) {
        TreeLinkNode *child = nullptr;
        TreeLinkNode *childHead = nullptr;
        
        while (parent) {
            while (parent) {
                if (parent->left) {
                    if (childHead) {
                        child->next = parent->left;
                    } else {
                        childHead = parent->left;
                    }
                    child = parent->left;
                }
                
                if (parent->right) {
                    if (childHead) {
                        child->next = parent->right;
                    } else {
                        childHead = parent->right;
                    }
                    child = parent->right;
                }
                
                parent = parent->next;
            }
            
            parent = childHead;
            child = nullptr;
            childHead = nullptr;
        }

    }
};
