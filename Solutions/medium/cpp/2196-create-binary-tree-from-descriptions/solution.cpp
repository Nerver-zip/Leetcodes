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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int,TreeNode*>> nodes; // key -> {parent, {inDegree {tree node}}
        
        for(const auto& description : descriptions){
            int p = description[0], c = description[1], isLeft = description[2];
            
            auto it_p = nodes.find(p);
            auto it_c = nodes.find(c);
            
            TreeNode *parent, *child;
            if(it_p == nodes.end()){
                parent = new TreeNode(p);
                nodes[p] = {0, parent};
            }
            else{
                parent = it_p->second.second;
            }

            if(it_c == nodes.end()){
                child = new TreeNode(c);
                nodes[c] = {1, child};
            }
            else{
                child = it_c->second.second;
                nodes[c] = {2, child};
            }

            if(isLeft)
                parent->left = child;
            else
                parent->right = child;
        }

        for(const auto& [_, p] : nodes){
            const auto& [deg, node] = p;
            if(deg == 0)
                return node;
        }

        return nullptr;
    }
};