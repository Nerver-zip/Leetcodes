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
class BSTIterator {
private:
    TreeNode *root; 
    std::stack<TreeNode*> *nodes;
      
    
    void stackNodes(TreeNode *root){
        while (root != nullptr)
        {
            nodes->push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root) {
        this->root = root;
        nodes = new std::stack<TreeNode*>();
        stackNodes(root);
    }
    
    int next() {
        if (nodes->empty())
        {
            return -1;
        }

        TreeNode *temp = nodes->top();
        nodes->pop();

        if (temp->right != nullptr)
        {
            stackNodes(temp->right);
        }
        return temp->val;
    }
    
    bool hasNext() {
        return !nodes->empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */