class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 0; i < s.size(); ++i){
            int left = -1, right = -1;
            if(i > 0)
                left = i-1;
            if(right < s.size()-1)
                right = i+1;

            int val = s[i] - '0';
            
            int leftVal = -1;
            int rightVal = -1;

            if(left != -1){
                leftVal = s[left] - '0';
                if(abs(val - leftVal) > 2)
                    return false;
            }
            if(right != -1){
                rightVal = s[right] - '0';
                if(abs(val - rightVal) > 2)
                    return false;
            }
        }    

        return true;
    }
};