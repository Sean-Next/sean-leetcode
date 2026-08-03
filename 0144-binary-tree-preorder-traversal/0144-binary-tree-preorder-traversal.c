/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct TreeNode TreeNode;

//计算二叉树节点总数
int BinaryTreeSize(TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
}

void PreOrder(TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
    {
        return;
    }

    arr[(*pi)++] = root->val;

    PreOrder(root->left, arr, pi);
    PreOrder(root->right, arr, pi);

    return;
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
    *returnSize = BinaryTreeSize(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));

    int i = 0;
    PreOrder(root, arr, &i);

    return arr;
}