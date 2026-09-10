class Solution {
public:
    int maxScore(string s) {
        string right = s;
        string left;

        int rightCount = 0;
        int leftCount = 0;

        int max = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if(right[i] == '1')
                rightCount++;
        }
        

        for (int i = 0; i < s.length()-1; i++)
        {
            left += right[i];
            if (left[i] == '0')
            {
                leftCount++;
            }
            else
            {
                rightCount--;
            }
            if (leftCount + rightCount > max)
                max = leftCount + rightCount;
        }
        return max;
    }
};