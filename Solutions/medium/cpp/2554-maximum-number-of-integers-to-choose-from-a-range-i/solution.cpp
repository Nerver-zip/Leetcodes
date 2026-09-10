
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        std::unordered_set<int> mySet;
        int sum = 0;
        int i = 1;
        int count = 0;

        for (auto element : banned)
        {
            mySet.insert(element);
        }

        while (i <= n)
        {
            if (mySet.find(i) == mySet.end()) {
                if (sum + i > maxSum)
                {
                    break;
                }
                sum += i;
                count++;
            }
            i++;
        }

        int greatest = i;
        while (sum <= maxSum && greatest <= n)
        {
            if (mySet.find(greatest) == mySet.end()) {
                if (sum + greatest > maxSum)
                {
                    break;
                }
                sum += greatest;
                count++;
            }
            greatest++;
        }
        return count;
    }
};