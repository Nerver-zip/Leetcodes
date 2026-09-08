class Solution {
private:
    bool canAllocateAll(const vector<int>& ranks, int totalCars, long long pivot){
        for (int i = 0; i < ranks.size() && totalCars > 0; i++)
        {   
            int allocatedCars = sqrt(pivot/ranks[i]); //max number of cars possible to be allocated given an amount and a mechanic
            totalCars = totalCars - allocatedCars;
        }
        return totalCars <= 0 ? true : false;    
    }
    long long binarySearchInterval(const vector<int>& ranks, long long left, long long right, int totalCars){
        long long ans; 
        while (left <= right)
        {
            long long mid = left + (right-left)/2;
            if (canAllocateAll(ranks,totalCars,mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else 
                left = mid + 1;
        }
        return ans;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long min = *std::min_element(ranks.begin(),ranks.end());
        int leftBound = 1;
        long long rightBound = (min) * pow(cars,2);;
        return binarySearchInterval(ranks, leftBound, rightBound, cars);
    }
};