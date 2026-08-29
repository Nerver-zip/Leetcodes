class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_map<int,int> map;

        for (int i = 0; i < arr.size(); i++)
        {
            map[arr[i]] = i;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            auto tgt = map.find(arr[i] * 2);
            if (tgt != map.end() && i != map[arr[i] * 2])
            {
                return true;
            }    
        }
        return false;
    }
};