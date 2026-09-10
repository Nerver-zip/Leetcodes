class Solution {
private:
    std::unordered_set<string> combinations;

    void combinate(std::unordered_map<char,int>& frequencyMap,const string& tiles, string curr, int index){
        if (curr.size() > 0 && index <= tiles.size() && combinations.find(curr) == combinations.end())
        {
            combinations.insert(curr);
        }
        for (int i = 0; i < tiles.size(); i++)
        {   
            int currLetter = frequencyMap[tiles[i]];
            if (currLetter)
            {
                curr += tiles[i];
                frequencyMap[tiles[i]]--;
                combinate(frequencyMap,tiles,curr,index+1);
                curr.pop_back();
                frequencyMap[tiles[i]]++;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {

        std::unordered_map<char,int> frequencyMap;

        for (const auto& letter : tiles)
        {
            frequencyMap[letter]++;
        }

        combinate(frequencyMap,tiles,"",0);
        
        return combinations.size();
    }
};