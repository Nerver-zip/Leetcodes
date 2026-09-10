/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *createNode(int val);
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);
struct ListNode *createNode(int val){
    struct ListNode *novo = (struct ListNode*)malloc(sizeof(struct ListNode));
    novo->val = val;
    novo->next = NULL;
    return novo;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2){
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    
    struct ListNode *head = NULL;
    struct ListNode *tail = NULL;
    bool carry = false;
    while (l1 != NULL || l2 != NULL)
    {
        int l1Value = (l1) == NULL ? 0 : l1->val;  
        int l2Value = (l2) == NULL ? 0 : l2->val;   
        int nodeValue; 
        if ((carry + l1Value + l2Value) < 10)
        {
            nodeValue = (carry + l1Value + l2Value);
            carry = false;
        }
        else
        {
            nodeValue = (carry + l1Value + l2Value) - 10;
            carry = true; 
        }
        struct ListNode *newNode = createNode(nodeValue);
        if (head == NULL) 
        {
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    if (carry)
    {
        struct ListNode *newNode = createNode(carry);
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

