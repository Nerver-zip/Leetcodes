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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        
        ListNode* temp = head;
        while(temp){
            nodes.push_back(temp);
            temp = temp->next;
        }
        

        int left = 0, right = nodes.size()-1;
        ListNode* last = head;        
        while(left < right){
            nodes[left++]->next = nodes[right];
            last = nodes[right];
            nodes[right--]->next = nodes[left];
            last = nodes[left];
        }
        last->next = nullptr;
    }
};