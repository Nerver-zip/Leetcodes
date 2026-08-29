class Solution {
public:
    int minMaxDifference(int num) {

        string maxNumber = to_string(num);
        string minNumber = maxNumber;
        
        char toReplace = ' ';
        for (auto& c : maxNumber){
            if(c != '9' && toReplace == ' ')
                toReplace = c;
            if(c == toReplace)
                c = '9';
        }

        int maximum = atoi(maxNumber.c_str());

        toReplace = ' ';
        for (auto& c : minNumber){
            if(c != '0' && toReplace == ' ')
                toReplace = c;
            if(c == toReplace)
                c = '0';
        }
        int minimum = atoi(minNumber.c_str());
    
        return maximum - minimum;
    }
};  