/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymmetric(struct TreeNode* root);
void isSymmetricAux(struct TreeNode *rootL, struct TreeNode *rootR, bool *flag); 

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    if (root->right == NULL && root->left == NULL)
    {
        return true;
    } 
    bool flag = true;
    isSymmetricAux(root->left,root->right,&flag);
    return flag;
}
void isSymmetricAux(struct TreeNode *rootL, struct TreeNode *rootR, bool *flag){
    if (rootL != NULL && rootR != NULL && *flag)
    {
        isSymmetricAux(rootL->left,rootR->right,flag);
        if (rootL->val != rootR->val)
        {
            *flag = false;
        }
        isSymmetricAux(rootL->right,rootR->left,flag);
    } 
    if (rootL == NULL && rootR != NULL)
    {
        *flag = false;
    }
    else if (rootL != NULL && rootR == NULL)
    {
        *flag = false;
    }
}