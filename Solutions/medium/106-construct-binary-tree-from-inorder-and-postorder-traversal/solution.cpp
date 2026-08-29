class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* rootMain = nullptr;
        int postIndex = postorder.size() - 1;

        auto solve = [&](int left, int right, auto&& self) -> TreeNode* {
            if(left > right)
                return nullptr;

            int rootVal = postorder[postIndex--];
            TreeNode* root = new TreeNode(rootVal);
            
            // encontra o índice da raiz no inorder
            int pivotIndex = left;
            for(; pivotIndex <= right; ++pivotIndex) {
                if(inorder[pivotIndex] == rootVal) 
                    break;
            }

            if(rootMain == nullptr)
                rootMain = root;
            
            // Post-order construir arvore direita primeiro
            // Perceber que na postOrder, os indices mais a direita
            // Pertencem as subarvores direitas excecao da primeira chamada
            // Se nao fizer assim, o indice da raiz no inorder nao sera encontrado
            root->right = self(pivotIndex+1, right, self);  
            root->left = self(left, pivotIndex-1, self);  
            return root;
        };

        TreeNode* root = nullptr;
        solve(0, inorder.size()-1, solve);
        
        return rootMain;    
    }
};