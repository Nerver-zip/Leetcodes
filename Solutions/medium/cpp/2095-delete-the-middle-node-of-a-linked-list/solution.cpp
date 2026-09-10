/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow_prev = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow && fast && fast->next != nullptr){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        slow_prev->next = slow->next;

        return slow == fast ? nullptr : head;
    }
};