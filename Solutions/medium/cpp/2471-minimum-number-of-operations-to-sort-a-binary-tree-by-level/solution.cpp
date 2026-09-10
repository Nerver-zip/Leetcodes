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
    int minimumOperations(TreeNode* root) {
    
    if (root == nullptr) return 0;

    std::vector<int> treeLevels;
    std::unordered_map<int,int> positionMap;
    std::queue<std::pair<TreeNode*,int>> q;
    int count = 0;
    
    q.push({root,0});
        
    int lastLevel = 0;
    int position = 0;

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second;
        q.pop();

        if(lastLevel != level){
            lastLevel = level;
            std::vector<int> sortedLevels = treeLevels;
            std::sort(sortedLevels.begin(),sortedLevels.end());
            for (int i = 0; i < treeLevels.size(); i++)
            {
               if (sortedLevels[i] != treeLevels[i])
               {
                count++;
                int originalPosition = positionMap[sortedLevels[i]];
                int originalNumber = treeLevels[i];
                std::swap(treeLevels[i],treeLevels[positionMap[sortedLevels[i]]]);
                positionMap[originalNumber] = originalPosition;
               }
            }
            treeLevels.clear();
            positionMap.clear();
            position = 0;
        }

        treeLevels.push_back(node->val);
        positionMap[node->val] = position++;
        
        if (node->left != nullptr)
            q.push({node->left,level + 1}); 

        if (node->right != nullptr)
            q.push({node->right,level + 1});
    }
    
    std::vector<int> sortedLevels = treeLevels;
    std::sort(sortedLevels.begin(),sortedLevels.end());
    for (int i = 0; i < treeLevels.size(); i++)
    {
       if (sortedLevels[i] != treeLevels[i])
       {
            count++;
            int originalPosition = positionMap[sortedLevels[i]];
            int originalNumber = treeLevels[i];
            std::swap(treeLevels[i],treeLevels[positionMap[sortedLevels[i]]]);
            positionMap[originalNumber] = originalPosition;
       }
    }
    return count;
    }
};