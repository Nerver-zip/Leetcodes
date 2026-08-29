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
    ListNode* swapPairs(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* newHead = head->next;
        ListNode* last = head->next;
        
        while (head != nullptr && head->next != nullptr)
        {
            ListNode* n1 = head;
            ListNode* n2 = head->next;
            
            head = head->next->next;
            
            last->next = n2;
            n2->next = n1;
            n1->next = head;
            last = n1;
        }
        return newHead;
    }
};