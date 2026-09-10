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

    TreeNode *lastNode;
    int errNum;

    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    TreeNode *lowestNode(TreeNode *root){
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }


public:

    Solution(){
        errNum = 0;
    }

    void recoverTree(TreeNode *root) { //Morris traversal
    lastNode = lowestNode(root); //inicialize lastNode with left most node
    TreeNode *curr = root;
    TreeNode *err1 = nullptr;
    TreeNode *err2 = nullptr;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            if (curr->val < lastNode->val)
            {   
                if (errNum >= 1)//Saves the next element that broke the order (input guaranteed to not have more than 2)
                {
                    err2 = curr;
                }
                else//Saves the two consecutive elements that broke the non decreasing order (they wont necessarely be swaped)
                {
                    err1 = lastNode;
                    err2 = curr;
                    errNum++;
                }
            }
            lastNode = curr;
            curr = curr->right;
        }
        else {
            TreeNode* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
                prev->right = nullptr;
            if (curr->val < lastNode->val)//Saves the next element that broke the order (input guaranteed to not have more than 2)
            {   
                if (errNum >= 1)
                {
                    err2 = curr;
                }
                else//Saves the two consecutive elements that broke the non decreasing order (they wont necessarely be swaped)
                {
                    err1 = lastNode;
                    err2 = curr;
                    errNum++;
                }
            }
                lastNode = curr;
                curr = curr->right;
            }
        }
    }
    if (errNum > 0)
    {
        swap(err1->val,err2->val);
    }
    
  }
};