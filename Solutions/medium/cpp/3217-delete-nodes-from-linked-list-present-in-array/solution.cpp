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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        ListNode* curr = head, *prev = head;
        while (curr) {
            if(numSet.count(curr->val)){
                prev->next = curr->next;
                if(curr == head)
                    head = curr->next;
            }
            else
                prev = curr;
            
            curr = curr->next;
        }
        return head;
    }
};