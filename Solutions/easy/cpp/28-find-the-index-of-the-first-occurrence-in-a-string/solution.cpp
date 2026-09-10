class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())
            return -1;
        
        int size = needle.size();
        
        for (int i = 0; i <= haystack.size() - size; ++i) {
            string curr = haystack.substr(i, size);

            if(!strcmp(curr.c_str(), needle.c_str()))
                return i;
        }
        return -1;
    }
};