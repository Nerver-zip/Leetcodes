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
private:
    ListNode* newHead = nullptr;
    ListNode* temp = nullptr;

    void reverse(ListNode* head){
        if (head->next != nullptr)
        {
            reverse(head->next);
        }
        if(newHead != nullptr){
            temp->next = head;
            temp = temp->next;
        }
        else
        {
            newHead = head;
            temp = head;
        }
    }

public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) 
            return nullptr;
        reverse(head);
        temp->next = nullptr;
        return newHead;
    }
};