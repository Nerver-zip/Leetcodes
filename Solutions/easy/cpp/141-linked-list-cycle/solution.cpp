/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;
        
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        
        while (fast != nullptr && fast->next != nullptr && fast != slow) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return fast == slow && slow != nullptr;
    }
};