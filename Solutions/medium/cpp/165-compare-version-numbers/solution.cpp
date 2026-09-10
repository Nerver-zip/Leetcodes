class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto p1 = version1.begin();
        auto p2 = version2.begin();
        
        while (p1 != version1.end() && p2 != version2.end()) {
            auto it1 = find(p1, version1.end(), '.');
            auto it2 = find(p2, version2.end(), '.');

            int val1 = atoi(std::string(p1, it1).c_str());
            int val2 = atoi(std::string(p2, it2).c_str());
            
            if(val1 > val2)
                return 1;
            else if(val1 < val2)
                return -1;

            p1 = (it1 == version1.end()) ? version1.end() : next(it1);
            p2 = (it2 == version2.end()) ? version2.end() : next(it2); 
        }

        while (p1 != version1.end()) {
            auto it1 = find(p1, version1.end(), '.');
            int val1 = atoi(std::string(p1, it1).c_str());

            if(val1 > 0)
                return 1;

            p1 = (it1 == version1.end()) ? version1.end() : next(it1);
        }

        while (p2 != version2.end()) {
            auto it2 = find(p2, version2.end(), '.');
            int val2 = atoi(std::string(p2, it2).c_str());

            if(val2 > 0)
                return -1;

            p2 = (it2 == version2.end()) ? version2.end() : next(it2);
        }

        return 0;
    }
};
