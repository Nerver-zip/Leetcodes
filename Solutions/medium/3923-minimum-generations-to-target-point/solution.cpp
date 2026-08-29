class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        string tgt = to_string(target[0]) + to_string(target[1]) + to_string(target[2]);
        unordered_set<string> set;

        auto pack = [](int x, int y, int z){
            return to_string(x) + to_string(y) + to_string(z);
        };

        auto unpack = [](const string& s)->array<int, 3>{
            return {(s[0] - '0'), s[1] - '0', s[2] - '0'};
        };

        int ans = 0;

        for(const auto& point : points){
            int x = point[0], y = point[1], z = point[2];
            
            auto s = pack(x,y,z);
            set.insert(s);  
        }

        if(set.count(tgt))
            return 0;

        // if new gen doesnt grow, stop
        vector<string> newGen;

        int prevSize = 0;
        while(prevSize != set.size()){
            prevSize = set.size();
        
            for(auto it = set.begin(); it != set.end(); ++it){
                for(auto it2 = set.begin(); it2 != set.end(); ++it2){
                    if(it == it2)
                        continue;
                    
                    auto [x1, y1, z1] = unpack(*it);
                    auto [x2, y2, z2] = unpack(*it2);

                    int x3 = (x1 + x2)/2;
                    int y3 = (y1 + y2)/2;
                    int z3 = (z1 + z2)/2;

                    auto s = pack(x3, y3, z3);

                    if(set.count(s))
                        continue;

                    newGen.push_back(s);
                }

            }
            
            for(const auto& s : newGen){
                if(!set.count(s))
                    set.insert(s);
            }
            
            newGen.clear();
            
            ++ans;
            if(set.count(tgt))
                return ans;
        }

        return -1;
    }
};