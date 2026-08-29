/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* increasingBST(struct TreeNode *root);
void organizeList(struct TreeNode *root, struct TreeNode **menor);
struct TreeNode *lowestNode(struct TreeNode *root);

struct TreeNode* increasingBST(struct TreeNode *root){
   struct TreeNode *menor = lowestNode(root);
   struct TreeNode *temp = menor;
    organizeList(root,&menor);
    return temp;
}

struct TreeNode *lowestNode(struct TreeNode *root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

void organizeList(struct TreeNode *root, struct TreeNode **menor){
    if (root != NULL)
    {
        organizeList(root->left,&(*menor));
        if (root == *menor)
        {
            return organizeList(root->right,&(*menor));
        }
        (*menor)-> right = root;
        (*menor) = (*menor)->right;
        root->left = NULL;
        organizeList(root->right,&(*menor));
    }
}