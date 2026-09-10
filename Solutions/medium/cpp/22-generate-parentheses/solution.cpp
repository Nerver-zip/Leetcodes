class Solution {
    vector<string> ans;
private:
    void validPermutations(string& curr, int L, int R, const int size){
        if (curr.size() == size * 2)
        {
            ans.push_back(curr);
            return;
        }
        if (L < size)
        {
            curr += '(';
            validPermutations(curr,L+1,R,size);
            curr.pop_back();
        }
        if (R < L)
        {
            curr += ')'; 
            validPermutations(curr,L,R+1,size);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {

        string curr;
        validPermutations(curr,0,0,n);
        
        return ans;
    }
};
