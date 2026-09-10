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
    ListNode* rightNxt = nullptr;
    int leftCount = 1;
    int rightCount = 1;

        void reverse(ListNode* head, int right){
        if (head->next != nullptr && rightCount < right-1)
        {
            rightCount++;
            reverse(head->next,right);
        }
        if(newHead != nullptr){
            temp->next = head;
            temp = temp->next;
        }
        else
        {
            newHead = head;
            temp = head;
            rightNxt = head->next;
        }
    }

public:

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* ogHead = head;

        if(head->next == nullptr) return head;

        if (left == 1)
        {
            reverse(head,++right);
            temp->next = rightNxt;
            return newHead;
        }
        //find left predecessor
        while (head->next != nullptr && leftCount < left-1)
        {
            head = head->next;
            leftCount++;
            rightCount++;
        }
        //reverse sublist left-right
        reverse(head->next,right); 

        //link main list to reversed sublist
        head->next = newHead; 
        temp->next = rightNxt;
        return ogHead;
    }
};
