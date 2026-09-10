class Solution {
private:
    void backtrack(vector<int>& powers, bool& found, int index, int curr, const int target){
        if (curr == target)
        {
            found = true;
            return;
        }
        for (int i = index; i < powers.size(); i++)
        {
            if (!found)
                backtrack(powers, found, i+1, curr + powers[i], target);        
        }
        return;
    }
public:
    bool checkPowersOfThree(int n) {
        vector<int> powers;

        int exp = 1;
        int res = 1;
        while (res <= n)
        {
            if (res == n) return true;
            powers.push_back(res);
            res = pow(3,exp++);
        }
        
        bool found = false;
        backtrack(powers, found, 0, 0, n);
        return found;
    }
};