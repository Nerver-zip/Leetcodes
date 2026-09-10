/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode *lowest = NULL;
    bool isSubtree(TreeNode *root, TreeNode *node){
        if (root == NULL)
        {
            return false;
        }
        else if (root == node)
        {
            return true;
        }
        else if (root->val > node->val)
        {
            return isSubtree(root->left,node);
        }
        else
        {
            return isSubtree(root->right,node);
        }
    }

    void findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root != NULL && (isSubtree(root,p) && isSubtree(root,q)))
        {
            lowest = root;
            findLCA(root->left,p,q);       
            findLCA(root->right,p,q);
        }   
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lowest = root;
        findLCA(root,p,q);
        return lowest;
    }
};
