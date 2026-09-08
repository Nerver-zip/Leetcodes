class Solution {
private:
    int maxSequence(const unordered_set<int>& sums, int a, int b){
        int count = 0;
        while (sums.find(a+b) != sums.end())
        {
            count++;
            int temp = b;
            b = a + b;
            a = temp;
        }
        return count;
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> sums;
        for (int i = 2; i < arr.size(); i++)
        {
            sums.insert(arr[i]);
        }

        int longestSeq = 0;
        int currSeq = 0;
        
        for (int i = 0; i < arr.size()-1; i++) 
        {
            for (int j = i+1; j < arr.size(); j++)
            {
                longestSeq = std::max(longestSeq,maxSequence(sums,arr[i],arr[j]));
            }
        }
        return longestSeq > 0 ? longestSeq + 2 : longestSeq;
    }
};