/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBSThelper(TreeNode* node, long long minVal, long long maxVal) {
        if(!node) {
            return true;
        }

        if(node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        return isBSThelper(node->left, minVal, node->val) &&
            isBSThelper(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return isBSThelper(root, LLONG_MIN, LLONG_MAX);
    }
};