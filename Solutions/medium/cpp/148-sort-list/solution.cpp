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
    ListNode* sortList(ListNode* head) {
        
        std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
        ListNode* temp = head;

        while (temp != nullptr)
        {
            minHeap.push(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        while (!minHeap.empty())
        {
            temp->val = minHeap.top();
            minHeap.pop();
            temp = temp->next;
        }
        return head;
    }
};