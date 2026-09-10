int *inorderTraversal(struct TreeNode* root, int *returnSize){
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = nodeCount(root);
    int *array = (int*)malloc(sizeof(int) * (*returnSize));
    int index = 0;
    inOrderArrayHelper(root,array,&index);
    return array;
}

void inOrderArrayHelper(struct TreeNode *root,int *array, int *index){
    if (root != NULL)
    {
       inOrderArrayHelper(root->left,array,index);
       array[(*index)++] = root->val;
       inOrderArrayHelper(root->right,array,index);
    }
}

int nodeCount(struct TreeNode *root){
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