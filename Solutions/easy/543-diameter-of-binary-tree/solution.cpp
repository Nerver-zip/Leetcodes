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
    int height(TreeNode* root, int h, int& max){
        if (root != nullptr)
        {
            height(root->left, h+1, max);
            max = std::max(max, h);
            height(root->right,h+1, max);
        }
        return max;
    }

    int maxHeightLeftRight(TreeNode* root, int& max){
        if (root != nullptr)
        {
            maxHeightLeftRight(root->left, max);
            int leftHeight = 0;
            int rightHeight = 0;
            int total = height(root->left,1,leftHeight) + height(root->right,1,rightHeight);
            max = std::max(total, max);
            maxHeightLeftRight(root->right, max);
        }
        return max;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        return maxHeightLeftRight(root, max);
    }
};