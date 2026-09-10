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
int *postorderTraversal(struct TreeNode *root, int* returnSize);
void postorderTraversalHelper(struct TreeNode *root,int *array,int *index);
int nodeCount(struct TreeNode *root);
void nodeCountHelper(struct TreeNode *root, int *count);

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = nodeCount(root);
    int *array = (int*)malloc(sizeof(struct TreeNode) * (*returnSize));
    int index = 0;
    postorderTraversalHelper(root,array,&index);
    return array;
}

void postorderTraversalHelper(struct TreeNode *root,int *array,int *index){
    if (root != NULL)
    { 
        postorderTraversalHelper(root->left,array,index);
        postorderTraversalHelper(root->right,array,index);
        array[(*index)++] = root->val;
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