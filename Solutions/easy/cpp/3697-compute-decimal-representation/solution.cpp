class Solution {
private:
    vector<int> decompose(int n){
        vector<int> res;
        while (n) {
            res.push_back(n%10);
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res = decompose(n);
        int k = res.size();
        int factor = pow(10, k-1);

        for (int& n : res) {
            n *= factor;
            factor /= 10;
        }

        vector<int> ans;
        for(int n : res)
            if(n > 0)
                ans.push_back(n);
        return ans;
    }
};