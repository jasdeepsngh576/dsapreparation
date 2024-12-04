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

    void insertBST(TreeNode* node, TreeNode* newNode)
    {
        if(newNode->val > node->val)
        {
            if(node->right)
            {
                insertBST(node->right, newNode);
            }
            else
            {
                node->right = newNode;
                return;
            }
        }
        else
        {
            if(node->left)
            {
                insertBST(node->left, newNode);
            }
            else
            {
                node->left = newNode;
                return;
            }
        }



    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode();
        newNode->val = val;
        if(root == NULL)
            return newNode;

        insertBST(root, newNode);
        return root;
    }
};