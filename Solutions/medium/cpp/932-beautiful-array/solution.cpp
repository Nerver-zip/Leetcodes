class Solution {
public:
    vector<int> beautifulArray(int n){
        if(n == 1) 
            return {1};

        auto left  = beautifulArray((n+1)/2);
        auto right = beautifulArray(n/2);

        vector<int> res;
        for(int x : left)  
            res.push_back(2*x - 1);
        for(int x : right) 
            res.push_back(2*x);

        return res;
    }
};