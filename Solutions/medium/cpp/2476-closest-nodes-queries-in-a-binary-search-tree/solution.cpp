/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * 
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    
    vector<vector<int>> answer;
    vector<int> nodes;

        void buildVector(TreeNode *root){
        if (root != nullptr)
        {
            buildVector(root->left);
            nodes.push_back(root->val);
            buildVector(root->right);
        }
    }
    
public:
    
    vector<int> binarySearchClosest(const vector<int> &array,vector<int> &queryAns,int left, int right, int value){
    if (left <= right)
    {
        int middle = left + (right-left)/2;

        if (array[middle] == value)
        {
            queryAns[0] = value;
            queryAns[1] = value;
            return queryAns;
        }

        if (array[middle] > value)
        {
            return binarySearchClosest(array,queryAns,left,middle-1,value);
        }
        return binarySearchClosest(array,queryAns,middle+1,right,value);
    }
    queryAns[0] = right < 0 ? array[0] : array[right];
    queryAns[1] = left > array.size()-1 ? array[array.size()-1] : array[left];
    if (queryAns[0] > value)
    {
        queryAns[0] = -1;
    }
    if (queryAns[1] < value)
    {
        queryAns[1] = -1;
    }
    return queryAns;
}

    vector<vector<int>> closestNodes(TreeNode* root, vector<int> &queries) {
        
        buildVector(root);
        int sizeQuery = queries.size();
        for (int i = 0; i < sizeQuery; i++)
        {
            vector<int> v(2, 0);
            binarySearchClosest(nodes, v, 0, nodes.size() - 1, queries[i]);
            answer.push_back(v);
        }
        return answer;
    }
};