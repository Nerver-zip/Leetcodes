class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        
        while (fast != nullptr && fast->next != nullptr && fast != slow)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;

        ListNode* collisionPoint = fast;
        ListNode* start = head;
        
        while (collisionPoint != start)
        {
            collisionPoint = collisionPoint->next;
            start = start->next;
        }
        
        return start;
    }
};