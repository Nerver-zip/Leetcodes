class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        const int size = encodedText.size();
        const int n = size/rows;

        vector<vector<char>> matrix(rows, vector<char>(0));

        for(int i = 0; i < encodedText.size(); ++i)
            matrix[i / n].push_back(encodedText[i]);
        

        auto getDiagonalString = [&matrix, &rows](int col){
            int r = 0, c = col;
            string text;
            while(r < rows && c < matrix[r].size()){
                text += matrix[r][c];
                ++r, ++c;
            }

            return text;
        };

        string originalText;
        for(int col = 0; col < matrix[0].size(); ++col)
            originalText += getDiagonalString(col);

        size_t idx_last = originalText.find_last_not_of(' ');
        if (idx_last == std::string::npos) {
            return "";
        }

        return originalText.substr(0, idx_last + 1);
    }
};