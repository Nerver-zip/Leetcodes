class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        
        if(k == 1)
            return 'a';

        long long len = 1;
        int type = 0;

        long long newK = -1;

        for (int i = 0; i < operations.size(); ++i)
        {
            len *= 2;

            if (len >= k)
            {
                type = operations[i];
                newK = k - len/2;
                break;
            }
        }
        char c = kthCharacter(newK, operations);
        if(type == 0) 
            return c;
        return c == 'z' ? 'a' : (c + 1);
    }
};