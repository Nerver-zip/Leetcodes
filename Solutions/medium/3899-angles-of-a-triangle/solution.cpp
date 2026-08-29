class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());

        if(sides[0] + sides[1] <= sides[2])
            return {};

        double a = sides[0], b = sides[1], c = sides[2];
        
        vector<double> ans;
        
        ans.push_back(acos((b*b + c*c - a*a) / (2 * b * c)) * 180.0 / M_PI);
        ans.push_back(acos((a*a + c*c - b*b)/ (2 * a * c)) * 180.0 / M_PI);
        ans.push_back(acos((b*b + a*a - c*c)/ (2 * a * b)) * 180.0 / M_PI);
        
        return ans;
    }
};