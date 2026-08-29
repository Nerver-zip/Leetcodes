class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        double maxDiag = -1.0;
        int ans = 0;

        for (const auto& rectangle : dimensions) {
            int a = rectangle[0], b = rectangle[1];
            double curr = sqrt(a*a + b*b); 
            
            if(curr > maxDiag){
                maxDiag = curr;
                ans = a * b;    
            }
            else if(curr == maxDiag){
                ans = max(ans, a * b);
            }            
        }
        return ans;
    }
};