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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<>> pq;

        for (const auto& list : lists) {
            ListNode* head = list;

            while(head){
                pq.push(head->val);
                head = head->next;
            }
        }
        
        
        if(lists.size() == 0 || pq.empty())
            return {};

        ListNode* newList = new ListNode(pq.top());
        pq.pop();

        ListNode* temp = newList;
        
        while (!pq.empty()) {
            temp->next = new ListNode(pq.top());
            pq.pop();
            temp = temp->next;
        }

        return newList;
    }
};