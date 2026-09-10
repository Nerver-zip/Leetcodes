/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *criarNodo(int val);
struct TreeNode *inserirNodo(struct TreeNode *root,int val);
struct TreeNode *sortedArrayToBST(int *array, int size);
void helperSortedArrayToBST(int *array, int size, struct TreeNode **root,int left, int right);
void destruirArvore(struct TreeNode **root);

struct TreeNode *criarNodo(int val){
    struct TreeNode *novo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    novo->val = val;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

struct TreeNode *inserirNodo(struct TreeNode *root,int val){
    if (root == NULL)
    {
        return criarNodo(val);
    }
    else if (root->val > val)
    {
        root->left = inserirNodo(root->left,val);
    }
    else if (root->val < val)
    {
        root->right = inserirNodo(root->right,val);
    }
    return root;
}

struct TreeNode* sortedArrayToBST(int *array, int size) {
   if (array == NULL || size == 0)
   {
    return NULL;
   }
   if (size == 1)
   {
    struct TreeNode *tree = criarNodo(array[0]);
    return tree;
   }
   
    struct TreeNode *tree = NULL;
    helperSortedArrayToBST(array,size,&tree,0,size-1);
    return tree;
}

void helperSortedArrayToBST(int *array, int size, struct TreeNode **root,int left, int right) {
    if (left <= right)
    {
        int middle = left + (right-left)/2;
        *root = inserirNodo(*root,array[middle]);
        helperSortedArrayToBST(array,size,&(*root),left,middle-1);
        helperSortedArrayToBST(array,size,&(*root),middle+1,right);
    }
    
}

void destruirArvore(struct TreeNode **root){
    if (*root != NULL)
    {
        destruirArvore(&(*root)->left);
        destruirArvore(&(*root)->right);
        free(*root);
        *root = NULL;
    }   
}