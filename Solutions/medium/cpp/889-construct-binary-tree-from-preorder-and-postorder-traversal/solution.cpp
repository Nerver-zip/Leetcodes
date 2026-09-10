class Solution {
private:
    TreeNode* constructTree(TreeNode* root, std::unordered_map<int,int>& postMap, const vector<int>&    preorder, const vector<int>& postorder, int leftPre, int rightPre, int leftPost){
        if (leftPre > rightPre)
        {
            return nullptr;
        }
        root = new TreeNode(preorder[leftPre]);
        if (leftPre != rightPre)
        {
            int leftVal = preorder[leftPre + 1];
            int middle =  postMap[leftVal];

            int leftSize = middle - leftPost + 1;
            root->left = constructTree(root,postMap,preorder,postorder,leftPre+1,leftPre + leftSize,leftPost); //left subtree
            root->right = constructTree(root,postMap,preorder,postorder,leftPre + leftSize + 1,rightPre,middle+1); //right subtree
        }
        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        std::unordered_map<int,int> postOrderMap;
        int size = preorder.size()-1;

        for (int i = 0; i < postorder.size(); i++)
            postOrderMap[postorder[i]] = i;
        TreeNode* root = nullptr;
        root = constructTree(root,postOrderMap,preorder,postorder,0,size,0);
        return root;
    }
};