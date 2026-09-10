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

    void buildVector(struct TreeNode *root){
        if (root != nullptr)
        {
        buildVector(root->left);
        nodes.push_back(root->val);
        buildVector(root->right);
        }
    }

public:
    int getMinimumDifference(TreeNode* root) {
        buildVector(root);
        int size = nodes.size();
        int dif = abs(nodes[0] - nodes[1]);
        for (int i = 0; i < size-1; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if (abs(nodes[i] - nodes[j]) < dif)
                {
                    dif = abs(nodes[i] - nodes[j]);
                }
            }
        }
        return dif;
    }
};