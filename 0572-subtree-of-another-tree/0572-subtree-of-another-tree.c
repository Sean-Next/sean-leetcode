/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p == NULL || q == NULL)
    {
        return false;
    }

    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) 
{
    if (isSameTree(root, subRoot))
    {
        return true;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return false;
    }

    if (root->left == NULL)
    {
        return isSubtree(root->right, subRoot);
    }

    if (root->right == NULL)
    {
        return isSubtree(root->left, subRoot);
    }

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}