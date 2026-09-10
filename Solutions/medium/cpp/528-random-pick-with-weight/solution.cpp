class Solution {
private:
    double totalSum = 0;
    vector<pair<double,int>> prefix;

    void binarySearch(int left, int right, double p, int& ans){
        if (left <= right)
        {
            int mid = left + (right - left)/2;
            if (prefix[mid].first < p)
            {
                ans = prefix[mid].second;
                return binarySearch(mid+1, right, p, ans); //look for a greater %P to the right
            }
            return binarySearch(left, mid-1, p, ans);
        }
        return;
    }

    double drawProbaility() {

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0); 
    
        return dis(gen);
    }
public:
    Solution(vector<int>& w) {
        for (const auto& n : w)
            totalSum += n;
        
        double interval = 1.0;
        
        for (int i = 0; i < w.size(); i++)
        {
            double p = w[i]/totalSum;
            prefix.push_back({p,i});
        }
        std::sort(prefix.begin(),prefix.end());

        for (int i = prefix.size()-1; i >= 0; i--)
        {
            interval = interval -  prefix[i].first;
            interval = interval < 0 ? 0 : interval;
            prefix[i].first = interval;
        }
    }
    
    int pickIndex() {
        double p = drawProbaility();
        int ans;
        binarySearch(0, prefix.size()-1, p, ans);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */