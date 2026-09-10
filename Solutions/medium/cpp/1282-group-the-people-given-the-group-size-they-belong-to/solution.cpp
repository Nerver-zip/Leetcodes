class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int>> size_person; //id-person 

        for (int i = 0; i < groupSizes.size(); i++)
            size_person.push_back({groupSizes[i],i});
        std::sort(size_person.begin(), size_person.end());
        
        vector<vector<int>> ans;
        vector<int> curr;
        int lastSize = 0;
        for (const auto& [size, person] : size_person)
        {   
            curr.push_back(person);
            if (curr.size() == size){
                ans.push_back(curr);
                curr.clear();
            }
        }
        return ans;
    }
};