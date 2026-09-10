class Solution {
public:
    int maxNumberOfBalloons(string text) {
        array<int, 26> freq;

        for(char c : text){
            ++freq[c - 'a'];
        }

        freq['l' - 'a'] /= 2;
        freq['o' - 'a'] /= 2;

        return min({freq['b' - 'a'], freq['a' - 'a'], freq['l' - 'a'], freq['o' - 'a'], freq['n' - 'a']});
    }
};