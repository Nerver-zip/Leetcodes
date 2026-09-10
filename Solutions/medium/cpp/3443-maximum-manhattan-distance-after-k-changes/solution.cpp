class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<char, int> freqMap;

        int maxDist = INT32_MIN;
        int north = 0, south = 0, east = 0, west = 0;
        for(char d : s){
            if (d == 'N') north++;
            else if (d == 'S') south++;
            else if (d == 'E') east++;
            else if (d == 'W') west++;

            int currDist = abs(north - south) + abs(east - west);
            int gain = min(2 * (min(north, south) + min(east, west)), 2 * k); 

            maxDist = max(maxDist, currDist + gain);
        }
        return maxDist;
    }
};