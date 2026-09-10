/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    TreeNode *insert(TreeNode *root, int value){
        if (root == NULL)
        {
            return new TreeNode(value);
        }
        else if (value < root->val)
        {
            root->left = insert(root->left,value);
        }
        else
        {
            root->right = insert(root->right,value);
        }
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    if (root == NULL) return "";

    std::queue<TreeNode*> q;
    string serial;

    q.push(root);

    while (!q.empty()) {
        
        TreeNode* node = q.front();
        string temp = std::to_string(node->val);
        for (int i = 0; temp[i] != '\0'; i++)
        {
            serial.push_back(temp[i]);
        }
        serial.push_back(',');
        q.pop();
        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
            q.push(node->right);
    }
    return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return NULL;

        string temp;
        TreeNode *tree = NULL;
        for (int i = 0; data[i] != '\0'; i++)
        {
            if (data[i] == ',')
            {
                tree = insert(tree,std::stoi(temp));
                temp = "";
                continue;
            }
            temp.push_back(data[i]);
        }
        return tree;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;