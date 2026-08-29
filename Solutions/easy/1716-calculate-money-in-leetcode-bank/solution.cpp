class Solution {
public:
    int totalMoney(int n) {
        int dayOfWeek = 0, starting = 0, currTotal, total = 0;

        while (n--) {
            if(dayOfWeek == 0){
                ++starting;
                currTotal = starting;
            }
            total += currTotal;
            ++currTotal;
            ++dayOfWeek;
            dayOfWeek %= 7;
        }

        return total;
    }
};