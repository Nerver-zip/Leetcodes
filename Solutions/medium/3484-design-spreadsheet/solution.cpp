class Spreadsheet {
private:
    vector<vector<int>> spreadsheet;
public:
    Spreadsheet(int rows) {
        spreadsheet.resize(26);

        for (int i = 0; i < 26; ++i)
            spreadsheet[i].assign(rows+1, 0);
    }
    
    void setCell(string cell, int value) {
        int row = cell[0] - 'A';
        int col = atoi(cell.substr(1).c_str());

        spreadsheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = cell[0] - 'A';
        int col = atoi(cell.substr(1).c_str());

        spreadsheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        int index = 0;
        
        string left, right;

        for(int i = 1; i < formula.size(); ++i){
            if(!left.empty() && left.back() == '+'){
                right += formula[i];
            }
            else
                left += formula[i];
        }
        left.pop_back();
        
        int row1 = -1, row2 = -1, col1 = -1, col2 = -1;
        int numLeft = -1, numRight = -1;

        if(left[0] > '9'){
            row1 = left[0] - 'A';
            col1 = atoi(left.substr(1).c_str());
        }
        else
            numLeft = atoi(left.c_str());
        
        if(right[0] > '9'){
            row2 = right[0] - 'A';
            col2 = atoi(right.substr(1).c_str());
        }
        else
            numRight = atoi(right.c_str());


        int totalLeft = numLeft == -1 ? spreadsheet[row1][col1] : numLeft;
        int totalRight = numRight == -1 ? spreadsheet[row2][col2] : numRight;

        return totalLeft + totalRight;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */