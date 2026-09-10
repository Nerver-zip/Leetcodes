class Solution {
private:
    int maxIndex(const vector<int>& freq){
        int index = 0;
        int max = -1;
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] > max)
            {
                max = freq[i];
                index = i;
            }
        }
        return index;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int size = tops.size();
        vector<int> totalFreq(6, 0);
        vector<int> topFreq(6, 0);
        vector<int> bottomFreq(6, 0);

        for (int i = 0; i < size; i++)
        {
            if (tops[i] == bottoms[i]) //duplicates contributes once towards total
                totalFreq[tops[i]-1]++;
            else
            {
                totalFreq[tops[i]-1]++;
                totalFreq[bottoms[i]-1]++;
            }
            topFreq[tops[i]-1]++;
            bottomFreq[bottoms[i]-1]++;
        }

        int index = maxIndex(totalFreq);
        int max = totalFreq[index];

        if(max < size)
            return -1;

        int count = 0;

        if (bottomFreq[index] > topFreq[index])
        {
            for (int i = 0; i < size; i++)
                if (bottoms[i] != index+1) //need to swap for the optimal sol
                    count++;
        }
        else
            for (int i = 0; i < size; i++)
                if (tops[i] != index+1)
                    count++;
        return count;
    }
};