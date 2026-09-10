class Solution {
private:
    vector<int> nums;
    bool dfs(int n, int curr){
        if (curr > n)
            return false;
        nums.push_back(curr);
        for (int i = 0; i < 10; ++i)
            if(!dfs(n, curr * 10 + i)) 
                break; //stop the searching in that level if curr is already bigger and return back a level
        return true;
    }
public:
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i < 10; ++i)
            if (!dfs(n, i))
                break;
        return nums;
    }
};