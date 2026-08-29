class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        std::unordered_set<char> seen1;
        std::unordered_set<char> seen2;
        int differ = 0;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                seen1.insert(s1[i]);
                seen2.insert(s2[i]);
                differ++;
                if (differ == 3)
                {
                    return false;
                }
            }
        }
        for (const auto& element : seen1)
        {
            if (seen2.find(element) == seen2.end())
            {
                return false;
            }
        }
        return differ == 0 || differ == 2 ? true : false;
    }
};