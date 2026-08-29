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
struct TreeNode *deleteNode(struct TreeNode *root, int key) {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (root->val > key)
        {
          root->left = deleteNode(root->left, key);
        }
        else if (root->val < key)
        {
          root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            else if (root->left == nullptr)
            {
                struct TreeNode *temp = root->right;
                return temp;
            }
            else if (root->right == nullptr)
            {
                struct TreeNode *temp = root->left;
                return temp;
            }
            else
            {
                struct TreeNode *temp = root->right;
                while (temp->left != nullptr)
                {                              
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
            }
        }
        return root;
    }  
public:
    struct TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root != nullptr)
        {
            root->left = trimBST(root->left,low,high);
            root->right = trimBST(root->right,low,high);
            if (root != nullptr && root->val < low || root->val > high)
            {
                root = deleteNode(root,root->val);
            }
        }
        return root;
    }
};