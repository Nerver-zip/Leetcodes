class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int SIZE = colors.size();
        int count = 0;
        int left = 0;
        int right = 1;

        bool last = colors[0];

    while (left < SIZE)
    {
        //Init the window
        for (right; right < k + left; right++)
        {
            //if it's the same color, skip until left = right and try to expand window again
            if (last == colors[right % SIZE])
            {
                left = right;
                if (left >= SIZE)
                    return count;
            }
            last = colors[right % SIZE];
        }
        count++;
        left++;
    }
        return count;
    }
};