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
    int pairSum(ListNode* head) {
        vector<int> nums;

        while(head){
            nums.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = nums.size()-1, ans = 0;

        while(left < right){
            ans = max(ans, nums[left] + nums[right]);
            ++left;
            --right;
        }

        return ans;
    }
};
