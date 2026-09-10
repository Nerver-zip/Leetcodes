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
    ListNode *mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        if (list1 != nullptr && list2 == nullptr)
        {
            return list1;
        }
        if (list1 == nullptr && list2 != nullptr)
        {
            return list2;
        }
        ListNode *head = nullptr;
        ListNode *last = nullptr;

        if (list1->val <= list2->val)
        {
            head = list1;
            last = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            last = list2;
            list2 = list2->next;
        }
    
        //Merge until we reach the end of either list
        //Similar to merge function in arrays
       while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                last->next = list1;
                last = list1;
                list1 = list1->next;
            }
            else
            {
                last->next = list2;
                last = list2;
                list2 = list2->next;
            }
        }
        if (list1 != nullptr && list2 == nullptr)
        {
            last->next = list1;

        }
        if (list2 != nullptr && list1 == nullptr)
        {
            last->next = list2;
        }
        return head;
    }
};