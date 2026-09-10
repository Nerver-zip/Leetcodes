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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* i_odd = head; //odd start
        ListNode* i_even = head->next; //even start
        ListNode* evenHead = i_even;

        ListNode* lastOdd = head;

        //While both havent reached the end
        while (i_odd || i_even) {
            if(i_odd && i_odd->next)
                i_odd->next = i_odd->next->next;
            if(i_even && i_even->next)
                i_even->next = i_even->next->next;
            
            if(i_odd)
                lastOdd = i_odd;
            
            //Move to next odd/even idx
            i_odd = i_odd ? i_odd->next : nullptr;
            i_even = i_even ? i_even->next : nullptr;
        }

        lastOdd->next = evenHead; //connect odd list to even list
        
        return head;
    }
};