
class Solution {
private:
    int countFromLast = 0;
    int countFromFirst = 1;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //recurse until the last node
        if (head->next != nullptr) 
        {   
            countFromFirst++;
            removeNthFromEnd(head->next,n);
        }
        countFromLast++;    
        //special case, deleting the first element
        if (countFromFirst == countFromLast && countFromLast == n)
        {
            ListNode *temp = head->next;
            delete head;
            return temp;
        }
        //at this point head will be the parent of the node 
        //which is going to be deleted
        if (countFromLast == n + 1) 
        {
            ListNode *temp = head->next;
            head->next = head->next->next;
            delete temp;
        }
        return head;
    }
};