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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;

        while(head){
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(nums.size(), 0);
    
        
        stack<int> st; //Monotonic decreasing

        for (int i = 0; i < nums.size(); ++i) {
            
            while (!st.empty() && nums[st.top()] < nums[i]) {
                ans[st.top()] = nums[i];
                st.pop();
            }

            st.push(i);
        }

        return ans;
    }
};
