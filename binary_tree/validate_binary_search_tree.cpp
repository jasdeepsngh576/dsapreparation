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

    pair<int, int> isValidBSTUtil(TreeNode* root, bool &ans)
    {

        pair<int, int> ret = make_pair(root->val, root->val);

        if(root->left)
        {
            pair<int, int> left = isValidBSTUtil(root->left, ans);
            if(left.second >= root->val)
                ans = false;

            ret.first = min(ret.first, left.first);
        }

        if(root->right)
        {
            pair<int, int> right = isValidBSTUtil(root->right, ans);
            if(right.first <= root->val)
                ans = false;

            ret.second = max(ret.second, right.second);
        }

        return ret;

    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;

        bool ans = true;   
        isValidBSTUtil(root, ans);
        return ans;
    }
};