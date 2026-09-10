struct Compare {
    bool operator()(const pair<vector<int>,char>& a, const pair<vector<int>,char>& b) const {

        for (int i = 0; i < a.first.size(); i++)
        {
            if (a.first[i] < b.first[i]) //Sorted by first value greater than it's counterpart
                return true; //a has priority over b
            if (a.first[i] > b.first[i])
                return false; //b has priority over a
        }
        return a.second > b.second; //if it's still tied, decide lexicographically
    }
};

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char,vector<int>> teamsVoteCount; //TEAM -> vector number of votes sorted from H - L
        for (const auto& vote : votes)
        {
            int place = 0;
            for (const auto& c : vote)
            {
                if(teamsVoteCount.find(c) == teamsVoteCount.end())
                    teamsVoteCount[c].resize(vote.size(),0); //Init vector inside map
                teamsVoteCount[c][place++]++; 
            }
        }
        
        priority_queue<pair<vector<int>,char>, vector<pair<vector<int>,char>>, Compare> maxHeap;
        
        for (const auto& [team, votes] : teamsVoteCount)
            maxHeap.push({votes, team});
        
        string ans;
        while (!maxHeap.empty())
        {
            ans += maxHeap.top().second;
            maxHeap.pop();
        }
        return ans;
    }
};