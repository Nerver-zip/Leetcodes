class Solution {

public:
    vector<string> generateValidStrings(int n, int k) {
        N = n;
        K = k;
        string curr;
        backtrack(curr, 0);
        return ans;
    }
private:
    vector<string> ans;
    int N;
    int K;
    void backtrack(string& curr, int cost){
        if(curr.size() == N){
            ans.push_back(curr);
            return;
        }
        curr.push_back('0');
        backtrack(curr, cost);
        curr.pop_back();

        if((curr.empty() || curr.back() != '1') && cost + curr.size() <= K){
            curr.push_back('1');
            backtrack(curr, cost + curr.size()-1);
            curr.pop_back();
        }
    }
};