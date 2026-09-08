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
// Since list is sorted, we only need to compare the prev and corrent element 
// and see if they are equal
// Assume caller calls free
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr) {

            if(prev->val == curr->val) //if equal, fix prev and update its next pointer
                prev->next = curr->next;
            else
                prev = prev->next; //otherwise advance prev alongside curr

            curr = curr->next;
        }

        return head;
    }
};