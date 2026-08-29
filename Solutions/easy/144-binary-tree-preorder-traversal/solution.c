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
int *preorderTraversal(struct TreeNode *root, int* returnSize);
void preorderTraversalHelper(struct TreeNode *root,int *array,int *index);
int nodeCount(struct TreeNode *root);
void nodeCountHelper(struct TreeNode *root, int *count);

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = nodeCount(root);
    int *array = (int*)malloc(sizeof(struct TreeNode) * (*returnSize));
    int index = 0;
    preorderTraversalHelper(root,array,&index);
    return array;
}

void preorderTraversalHelper(struct TreeNode *root,int *array,int *index){
    if (root != NULL)
    {
        array[(*index)++] = root->val;
        preorderTraversalHelper(root->left,array,index);
        preorderTraversalHelper(root->right,array,index);
    }
}

int nodeCount(struct TreeNode *root){
    int count = 0;
    nodeCountHelper(root,&count);
    return count;
}

void nodeCountHelper(struct TreeNode *root, int *count){
    if (root != NULL)
    {
        nodeCountHelper(root->left,count);
        (*count)++;
        nodeCountHelper(root->right,count);
    }
}