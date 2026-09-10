/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *findMode(struct TreeNode* root, int *size);
void findModeHelper(struct TreeNode* root, struct TreeNode **lastNode, int *array,int *count, int *lastCount, int *index);
struct TreeNode *lowestNode(struct TreeNode *root);
int nodeCount(struct TreeNode *root);
void nodeCountHelper(struct TreeNode *root, int *count);

int *findMode(struct TreeNode* root, int *size) {
    struct TreeNode *lastNode = NULL;
    lastNode = lowestNode(root);
    int count = 0;
    int count2 = 0;
    int index = 0;
    int *array = (int*)malloc(sizeof(int) * nodeCount(root));
    array[0] = lastNode->val;
    findModeHelper(root,&lastNode,array,&count,&count2,&index);
    *size = index+1;
    return array;
}
void findModeHelper(struct TreeNode* root, struct TreeNode **lastNode, int *array,int *count, int *maxCount, int *index){
    if (root != NULL)
    {
        findModeHelper(root->left,&(*lastNode),array,count,maxCount,index);
        if (root == *lastNode)
        {
        //return once first node of inorder traversal is found
        return findModeHelper(root->right,&(*lastNode),array,count,maxCount,index);
        }
        if ((*lastNode)->val == root->val)
        {
            (*count)++;
            if (*count == *maxCount) //add new element to the array
            {   
                (*index)++;
                array[(*index)] = root->val;  
            }
            else if (*count > *maxCount ) //overwrite if count is greater then current max
            {
                (*index) = 0;
                array[(*index)] = root->val;
                *maxCount = *count;
            }
        }
        else if ((*lastNode)->val != root->val){
            (*count) = 0;
            if (*count == *maxCount)
            {
            (*index)++;
            array[(*index)] = root->val;
            }
        }
        *lastNode = root; //update last node to current node       
        findModeHelper(root->right,&(*lastNode),array,count,maxCount,index);
        }
    }

struct TreeNode *lowestNode(struct TreeNode *root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

int nodeCount(struct TreeNode *root){
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    nodeCountHelper(root,&count);
    return count;
}

void nodeCountHelper(struct TreeNode *root, int *count){
    if (root != NULL)
    {
       nodeCountHelper(root->left,count);
       (*count)++;
       nodeCountHelper(root->right,count);
    }
}
