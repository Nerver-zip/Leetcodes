class Solution {
public:
    int minimumDeletions(string s) {
        const int n = s.size();

        vector<int> a_suffix(n);

        a_suffix[n-1] = s[n-1] == 'a' ? 1 : 0;
        for(int i = n-2; i >= 0; --i){
            if(s[i] == 'a')
                a_suffix[i] = a_suffix[i+1] + 1;
            else
                a_suffix[i] = a_suffix[i+1];
        }
        
        int ans = INT_MAX;
        int a_count = 0, b_count = 0;
        for(int i = 0; i < n; ++i){
            // to guarantee a valid ans here we delete all b to the left and all a to right
            // when we get to "deleted a's" later, we can see if keeping them was better
            if(s[i] == 'a'){
                ++a_count;
                ans = min(ans, b_count + a_suffix[i]-1);
            }
            // here we delete every 'b' to the left so they dont mess with left a's
            // and also every 'a' to the right of course
            // but what if we want to keep 'b's to the left?
            // well, turns out we have already scanned those on a past iteration
            else{ 
                ++b_count;
                ans = min(ans, a_suffix[i] + b_count-1);
            }
        }
        
        return ans;
    }
};