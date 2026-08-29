/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root);
void isValidHelper(struct TreeNode* root, struct TreeNode **lastNode, bool *flag);
struct TreeNode *lowestNode(struct TreeNode *root);

bool isValidBST(struct TreeNode* root) {
    struct TreeNode *lastNode = NULL;
    lastNode = lowestNode(root);
    bool flag = true;
    isValidHelper(root,&lastNode, &flag);
    return flag;
}
//do inorder traversal while lastNode is less than current node
void isValidHelper(struct TreeNode* root, struct TreeNode **lastNode, bool *flag){
    if (root != NULL && *flag)
    {
        isValidHelper(root->left,&(*lastNode),flag);
        if (root == *lastNode)
        {
        //return once first node of inorder traversal is found
        return isValidHelper(root->right,&(*lastNode),flag);
        }
        if ((*lastNode)->val >= root->val)
        {
            *flag = false;
            return;
        }
        *lastNode = root; //update last node to current node       
        isValidHelper(root->right,&(*lastNode),flag);
    }
}

struct TreeNode *lowestNode(struct TreeNode *root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
