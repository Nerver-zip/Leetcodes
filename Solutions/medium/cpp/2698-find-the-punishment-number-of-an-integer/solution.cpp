class Solution {
private:
    bool canPartition(int index, int current, int target, const string& str){   
        if (index == str.size()) {
            return current == target;
        }

        for (int i = index + 1; i <= str.size(); i++) {
            int num = stoi(str.substr(index, i - index)); 
            if (canPartition(i, current + num, target, str)) {  
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            string str = std::to_string(i * i);  
            if (canPartition(0, 0, i, str)) {  
                sum += i * i; 
            }
        }     
        return sum;
    }
};