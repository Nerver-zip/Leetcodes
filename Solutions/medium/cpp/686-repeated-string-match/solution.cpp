class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(a == b)
            return 1;
        
        int count = 1;
        const string og_a = a;
        
        while (a.size() < b.size()) {
            a.append(og_a, 0, og_a.size());
            ++count;
        }
        
        int loopCount = 0;
        while (loopCount < 3) {
            if(a.find(b) != string::npos)
                return count;

            count++;
            loopCount++;
            a.append(og_a,0,og_a.size());
        }
        
        return -1;
    }
};