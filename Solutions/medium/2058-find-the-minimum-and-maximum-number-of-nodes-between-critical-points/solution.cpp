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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> points;

        while(head){
            points.push_back(head->val);
            head = head->next;
        }
            
        auto isCritPoint = [&points](int idx) {
            return (points[idx - 1] < points[idx] && points[idx] > points[idx + 1]) ||
                   (points[idx - 1] > points[idx] && points[idx] < points[idx + 1]);
        };
        
        int minDist = numeric_limits<int>::max();
        int prev = -1;
        int first = -1;
        int last = -1;
        int count = 0;

        for(int i = 1; i < points.size()-1; ++i){
            if(isCritPoint(i)){
                ++count;
                if(prev == -1){
                    first = prev = i;
                }
                else{
                    minDist = min(minDist, i - prev);
                    prev = i;
                }
                last = i;
            }
        }

        return count <= 1 ? vector<int>{-1,-1} : vector<int>{minDist,last - first};
    }
};