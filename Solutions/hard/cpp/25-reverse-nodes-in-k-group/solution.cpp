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

public:
    void reverseNodesHelper(ListNode* head, int n, ListNode** newHead, ListNode** tail, ListNode** remainder){
        if (head->next != nullptr && --n)
        {
            reverseNodesHelper(head->next,n,newHead,tail,remainder);
        }
        if (*newHead != nullptr)
        {
            (*tail)->next = head;
            *tail = (*tail)->next;
        }
        else
        {
            *newHead = head;
            *tail = head;
            *remainder = head->next;
        }
        return;
    }

    ListNode* reverseKGroup(ListNode* head, int k){ 
        ListNode* ogHead = head;
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        ListNode* remainder = nullptr;

        int nodeCount = 0;
        ListNode* countHelper = head;

        while (countHelper != nullptr)
        {
            nodeCount++;
            countHelper = countHelper->next;
        }
        
        nodeCount = nodeCount - k;
        reverseNodesHelper(head,k,&newHead,&tail,&remainder);
        ogHead = newHead;
        tail->next = remainder;

        ListNode* temp = tail;

        for (nodeCount; nodeCount >= k ; nodeCount = nodeCount - k)
        {
            newHead = nullptr;
            reverseNodesHelper(remainder,k,&newHead,&tail,&remainder);
            if (nodeCount == k)
            {
                temp->next = newHead;
                tail->next = nullptr;
                temp = tail;
                return ogHead;
            }
            temp->next = newHead;
            tail->next = remainder;
            temp = tail;
        }
        return ogHead;
    }
};