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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        // Check if the current node is a leaf
        if (root->left == nullptr && root->right == nullptr) {
            return targetSum == root->val;
        }

        // Subtract current node's value and explore both subtrees
        int remaining = targetSum - root->val;

        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};