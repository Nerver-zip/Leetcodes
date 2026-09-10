/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
    int sum = 0;

    void sumUp(TreeNode *root){
        if (root != nullptr)
        {
            sumUp(root->left);
            sum += root->val;
            sumUp(root->right);
        }
    }

    void bstToGreater(TreeNode *root){
        if (root != nullptr)
        {
            bstToGreater(root->left);
            int temp = root->val;
            root->val = sum;
            sum = sum - temp;
            bstToGreater(root->right);
        }
    }

public:
    TreeNode *convertBST(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        sumUp(root);
        bstToGreater(root);
        return root;
    }
};