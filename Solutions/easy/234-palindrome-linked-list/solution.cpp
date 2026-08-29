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
    ListNode *temp;
public:
    bool isPalindrome(ListNode* head) {
        bool flag = true;
        temp = head;
        isPalindrome(head,flag);
        return flag;
    }

    void isPalindrome(ListNode* head, bool& flag) {
        if (head->next != nullptr)
        {
            isPalindrome(head->next,flag);
        }
        if(temp->val != head->val) flag = false;
        temp = temp->next;
    }
};