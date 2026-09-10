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
    std::vector<int> nodes;
    void buildVectorInOrder(struct TreeNode *root){
        if (root != nullptr)
        {
            buildVectorInOrder(root->left);
            nodes.push_back(root->val);
            buildVectorInOrder(root->right);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k){
        buildVectorInOrder(root);
        return nodes[k-1];
    }
};
