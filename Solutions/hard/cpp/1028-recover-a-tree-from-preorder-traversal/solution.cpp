class Solution {
private:

    vector<std::pair<int,int>> treeLevels(string traversal){
        std::vector<std::pair<int,int>> nodes;
        int count = 0;
        string num;
        for (int i = 0; i < traversal.size(); i++)
        {
            if (traversal[i] == '-')
                count++;
            else
            {   
                if (i < traversal.size() - 1 && traversal[i+1] != '-')
                {
                   num += traversal[i]; 
                }
                else if(i < traversal.size() - 1 && traversal[i+1] == '-' || i == traversal.size()-1)
                {
                    num += traversal[i];
                    nodes.push_back({atoi(num.c_str()),count});
                    num.clear();
                    count = 0;
                }
            }
        }
        return nodes;
    }

    void buildTree(TreeNode* root, const vector<std::pair<int,int>>& nodes){
        
        std::unordered_map<int,TreeNode*> nodeMap; //level, node
        nodeMap[nodes[0].second] = root;

        TreeNode* current = root;

        for (int i = 1; i < nodes.size(); i++)
        {   
            //only update if curr level is less than or equal to the previous
            current = nodeMap[nodes[i].second] == nullptr || nodes[i].second > nodes[i-1].second ? current : nodeMap[nodes[i].second];
            if (current->left == nullptr)
            {
                current->left = new TreeNode(nodes[i].first);
                nodeMap[nodes[i].second] = current;
                current = current->left;
            }
            else if (current->right == nullptr)
            {
                current->right = new TreeNode(nodes[i].first);
                nodeMap[nodes[i].second] = current; 
                current = current->right;
            }
        }
        return; 
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<std::pair<int,int>> nodes = treeLevels(traversal);
        
        TreeNode* root = new TreeNode(nodes[0].first);
        buildTree(root,nodes);
        return root;
    }
};