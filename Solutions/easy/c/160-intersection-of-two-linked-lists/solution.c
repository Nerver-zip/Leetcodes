/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *aux = headB;

    while (headA != NULL)
    {
        while (aux != NULL)
        {
            if (aux == headA)
            {
                return aux;
            }
            aux = aux->next;
        }
        headA = headA->next;
        aux = headB;
    }
    return NULL;
}