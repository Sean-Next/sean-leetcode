/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root) 
{
    if (root == NULL)
    {
        return true;
    }

    int left, right;
    left = right = root->val;

    if (root->left)
    {
        left = root->left->val;
    }
    if (root->right)
    {
        right = root->right->val;
    }

    if (root->val == left && root->val == right)
    {
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }

    return false;
}