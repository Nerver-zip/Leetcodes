/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root);
void maxDepthHelper(struct TreeNode *root, int *depth, int *maxDepth);

int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }
    int maxDepth = 0;
    int depth = 0;
    maxDepthHelper(root,&depth,&maxDepth);
    return maxDepth;
}

void maxDepthHelper(struct TreeNode *root, int *depth, int *maxDepth){
    if (root != NULL)
    {
        (*depth)++;
        maxDepthHelper(root->left,depth,maxDepth);
        (*depth)++;
        maxDepthHelper(root->right,depth,maxDepth);
    }
    if (*depth > *maxDepth)
    {
        *maxDepth = *depth;
    }
    (*depth)--;
}