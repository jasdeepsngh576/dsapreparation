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

    int dBTUtil(TreeNode* root, int &maxPath)
    {
        if(root == NULL)
        {
            return 0;
        }

        int maxLeft = dBTUtil(root->left, maxPath);
        int maxRight = dBTUtil(root->right, maxPath);

        maxPath = max(maxPath, maxLeft + maxRight);

        return 1 + max(maxLeft, maxRight);

    }

    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL)
            return 0;

        int maxPath = INT_MIN;
        dBTUtil(root, maxPath);

        return maxPath;
        
    }
};