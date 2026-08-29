/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *tree = nullptr;
    std::vector<int> nodes;
    
    void buildVector(ListNode *head){
        while (head != nullptr)
        {
            nodes.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode *insertion(TreeNode *root, int value){
        if (root == nullptr)
        {
           return new TreeNode(value);
        }
        else if (root->val > value)
        {
            root->left = insertion(root->left,value);
        }
        else if (root->val < value)
        {
            root->right = insertion(root->right,value);
        }
        return root;
    }

    void organizeTree(int left, int right){
        if (left <= right)
        {
            int middle = left + (right - left)/2;
            tree = insertion(tree,nodes[middle]);
            organizeTree(left, middle-1);
            organizeTree(middle+1,right);
        }
    }

public:
    TreeNode *sortedListToBST(ListNode* head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        buildVector(head);
        organizeTree(0,nodes.size()-1);
        return tree;
    }
};