class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* newHead = nullptr;
        ListNode* temp = head;
        ListNode* temp2 = nullptr;

        while (temp != nullptr)
        {
            if (temp->val < x)
            {
                if (!newHead)
                {
                    newHead = new ListNode(temp->val);
                    temp2 = newHead;
                }
                else
                {
                    temp2->next = new ListNode(temp->val);
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }
        
        temp = head;
        while (temp != nullptr)
        {
            if (temp->val >= x)
            {
                if (!newHead)
                {
                    newHead = new ListNode(temp->val);
                    temp2 = newHead;
                }
                else
                {
                    temp2->next = new ListNode(temp->val);
                    temp2 = temp2->next;
                }
            }
            temp = temp->next;
        }
        return newHead;
    }
};