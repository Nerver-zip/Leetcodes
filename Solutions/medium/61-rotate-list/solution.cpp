class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return head;

        auto [size, tail] = [&]()->pair<int, ListNode*>{
            ListNode* temp = head;
            int res = 0;
            ListNode* tail;

            while(temp){
                tail = temp;
                temp = temp->next;
                ++res;
            }
            return {res, tail};
        }();

        k %= size;
        if(k == 0)
            return head;
        
        int shift = size - k;
        tail->next = head;
        
        ListNode* newHead = head;
        while(shift){
            newHead = newHead->next;
            --shift;
        }
        
        // newHead->prev->next should point to null
        ListNode* temp = tail;

        while(temp->next != newHead)
            temp = temp->next;

        temp->next = nullptr;
        return newHead;
    }
};
