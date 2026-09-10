#define INF 1000
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int white = 0;
        int minWhite = INF;

        int right = 0;
        for (right = 0; right < k; right++)
        {
            if (blocks[right] == 'W')
                white++;
        }
        if (white == 0) return 0;
        minWhite = std::min(minWhite,white);
 
        int left = 0;
        for (right; right < blocks.size() && minWhite != 0; right++)
        {
            if (blocks[left] == 'W')
                white--;
            if(blocks[right] == 'W')
                white++;
            minWhite = std::min(minWhite,white);
            left++;
        }
        return minWhite;
    }
};
