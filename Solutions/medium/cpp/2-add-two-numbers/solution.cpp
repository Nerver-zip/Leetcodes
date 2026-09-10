class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1, s2;
        
        while(l1){
            s1 += to_string(l1->val);
            l1 = l1->next;
        }

        while(l2){
            s2 += to_string(l2->val);
            l2 = l2->next;
        }
        
        int res = 0;
        bool carry = 0;
        string ans;
        
        int i = 0, j = 0;
        for(; i < s1.size() && j < s2.size(); ++i, ++j){
            int a = s1[i] - '0', b = s2[j] - '0';
            res = (a + b + carry) % 10;

            if(a + b + carry >= 10)
                carry = 1;
            else
                carry = 0;
            
            ans += to_string(res);
        }

        while(i < s1.size()){
            int a = s1[i] - '0';

            res = (a + carry) % 10;

            if(a + carry >= 10)
                carry = 1;
            else
                carry = 0;
            ans += to_string(res);
            ++i;
        }

        while(j < s2.size()){
            int a = s2[j] - '0';

            res = (a + carry) % 10;

            if(a + carry >= 10)
                carry = 1;
            else
                carry = 0;
            ans += to_string(res);
            ++j;
        }
        
        if(carry)
            ans += '1';

        ListNode* head = new ListNode(ans[0] - '0');
        ListNode* list = head;
        for(int i = 1; i < ans.size(); ++i){
            list->next = new ListNode(ans[i] - '0');
            list = list->next;
        }
        
        return head; 
    }
};