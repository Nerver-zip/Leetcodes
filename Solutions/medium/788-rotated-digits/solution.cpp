class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int x = 1; x <= n; ++x)
            if(isGoodInteger(x))
                ++ans;
        return ans; 
    }
private:
    bool isGoodInteger(int x){
        string s = to_string(x);

        for(char& c : s){
            if(c == '3' || c == '4' || c == '7')
                return false;
            else if(c == '5')
                c = '2';
            else if(c == '2')
                c = '5';
            else if (c == '6')
                c = '9';
            else if(c == '9')
                c = '6';
        }

        int y = stoi(s);

        return x != y;
    }
};