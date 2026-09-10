/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isBalanced(struct TreeNode* root);
void isBalancedAux(struct TreeNode* root, bool *flag);
bool isBalancedSubTree(struct TreeNode* root);
int maxDepth(struct TreeNode* root);
void maxDepthHelper(struct TreeNode *root, int *depth, int *maxDepth);

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    bool flag = true;
    isBalancedAux(root,&flag);
    return flag;
}

void isBalancedAux(struct TreeNode* root, bool *flag){
    if (root != NULL && *flag)
    {
        isBalancedAux(root->left,flag);
        if (!isBalancedSubTree(root))
        {
            *flag = false;
        }
        isBalancedAux(root->right,flag);
    }
}

bool isBalancedSubTree(struct TreeNode* root) {
    int balanceFactor = maxDepth(root->left) - maxDepth(root->right);
    return balanceFactor > 1 || balanceFactor < -1 ? false : true;
}

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