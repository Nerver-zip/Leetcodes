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

    std::vector<int> values;

    void buildArray(struct TreeNode *root){
        if (root != nullptr)
        {
        buildArray(root->left);
        values.push_back(root->val);
        buildArray(root->right);
        }
    }
    
public:
    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr)
        {
            return false;
        }
        buildArray(root);
    for (int i = 0; i < values.size()-1; i++)
    {
        for (int j = i+1; j < values.size(); j++)
        {
            if (values[i] + values[j] == k)
            {
                return true;
            }
        }
    }
    return false;
    }
};