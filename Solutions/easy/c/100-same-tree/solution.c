/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode *p, struct TreeNode *q);
void isSameTreeAux(struct TreeNode *p, struct TreeNode  *q, bool *flag);

bool isSameTree(struct TreeNode *p, struct TreeNode *q){
    if (p == NULL && q == NULL)
    {
        return true;
    }
    bool flag = true;
    isSameTreeAux(p,q,&flag);
    return flag;
}

void isSameTreeAux(struct TreeNode *p, struct TreeNode  *q, bool *flag) {
    if (p != NULL && q != NULL && *flag != false)
    {
        isSameTreeAux(p->left,q->left,flag);
        if (p->val != q->val)
        {
            *flag = false;
        } 
        isSameTreeAux(p->right,q->right,flag);
    }
    if (p == NULL && q != NULL)
    {
        *flag = false;
    }
    else if (p != NULL && q == NULL)
    {
        *flag = false;
    }
}