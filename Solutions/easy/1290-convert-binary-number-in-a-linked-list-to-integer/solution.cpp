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
    int getDecimalValue(ListNode* head) {
        int size = -1;
        ListNode* temp = head;
        while (temp){
            temp = temp->next;
            ++size;
        }
            
        int ans = 0;

        while (head)
        {
            ans += pow(2, size) * head->val;
            head = head->next;
            --size;
        }
        return ans;
    }
};