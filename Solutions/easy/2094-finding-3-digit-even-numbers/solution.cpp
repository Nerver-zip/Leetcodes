class Solution {
private:
    vector<int> digitArray(int n){
        vector<int> digitFreq(10, 0);
        while (n)
        {
            digitFreq[n % 10]++;
            n /= 10;
        }
        return digitFreq;
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digitFreq(10, 0);
        vector<int> ans;

        for (const auto& d : digits)
            digitFreq[d]++;

        bool push;
        for (int i = 100; i <= 999; ++i)
        {
            if(i % 2 != 0)
                continue;
            push = true;
            vector<int> temp = digitArray(i);
            for (int j = 0; j < 10; ++j)
            {
                if(temp[j] > digitFreq[j])
                {
                    push = false;
                    break;
                }
            }
            if(push)
                ans.push_back(i);
        }
        return ans;
    }
};