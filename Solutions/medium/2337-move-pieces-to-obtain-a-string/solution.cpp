class Solution {
private:
    string removeUnder(string &str){
        string newStr;
        for (auto s : str)
        {
            if (s != '_')
            {
                newStr += s;
            }
        }
        return newStr;
    } 
public:
    bool canChange(string start, string target) {
        //compare strings without underscores
        if (removeUnder(start) != removeUnder(target)) return false;

        //then make sure that every L in 'start' has a greater or equal index than its L counter part in target
        int i = 0;

        int targetIndex = 0;
        int startIndex = 0;
        int targetCount = 0;
        int startCount = 0;

        while (i < start.size())
        {
            if (target[i] == 'L')
            {
                targetIndex = i;
                targetCount++;
            }
            if (start[i] == 'L')
            {
                startIndex = i;
                startCount++;
            }
            if (startCount >= targetCount && startIndex < targetIndex)
                return false;
            i++;
        }
        i = 0;

        targetIndex = 0;
        startIndex = 0;
        targetCount = 0;
        startCount = 0;

        //make sure that every R in 'target' has a lower or equal index than its R counter part in start
        while (i < start.size())
        {
            if (target[i] == 'R')
            {
                targetIndex = i;
                targetCount++;
            }
            if (start[i] == 'R')
            {
                startIndex = i;
                startCount++;
            }
            if (startCount <= targetCount && startIndex > targetIndex)
                return false;
            i++;
        }   
        return true;
    }
};