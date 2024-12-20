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

    int isBalancedUtil(TreeNode* root, bool &balanced)
    {
        if(root == NULL)
        {
            return 0;
        }

        int left = isBalancedUtil(root->left, balanced);
        int right = isBalancedUtil(root->right, balanced);

        if(abs(left - right) > 1)
            balanced = false;

        return 1 + max(left, right);

    }

    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        isBalancedUtil(root, balanced);
        return balanced;
    }
};