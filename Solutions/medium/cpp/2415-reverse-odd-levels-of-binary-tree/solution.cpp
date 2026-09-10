class Solution {

private:

    void reverseOddLevelsHelper(TreeNode* left, TreeNode* right, int level){
        if (left == nullptr)
        {
            return;
        }
    
        if (level % 2 == 0)
        {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }
        reverseOddLevelsHelper(left->left,right->right,level ^ 1);
        reverseOddLevelsHelper(left->right,right->left,level ^ 1);
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        
    if (root == nullptr) return root;

    reverseOddLevelsHelper(root->left,root->right,0);
    
    return root;
}

};