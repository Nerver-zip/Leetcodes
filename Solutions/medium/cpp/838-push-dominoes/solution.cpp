struct Compare {
    bool operator()(const array<int,3>& a, const array<int,3>& b) const {
        return a[0] > b[0]; //Min heap sorted by first element
    }
};

class Solution {
public:
    string pushDominoes(string dominoes) {
        int size = dominoes.size();
        string ans = dominoes;
        priority_queue<array<int,3>, vector<array<int,3>>, Compare> minHeap; //time, index, momentum direction
        vector<int> timeLeft(dominoes.size(), INT_MAX);
        vector<int> timeRight(dominoes.size(), INT_MAX);

        for (int i = 0; i < size; i++){
            if (dominoes[i] == 'L'){
                minHeap.push({0, i, 'L'});
                timeLeft[i] = 0;
            }
            else if(dominoes[i] == 'R'){
                minHeap.push({0, i, 'R'});
                timeRight[i] = 0;
            }
        }    

        while (!minHeap.empty())
        {
            auto [currTime, currIndex, currSide] = minHeap.top();
            minHeap.pop();

            if (currTime > timeLeft[currIndex] || currTime > timeRight[currIndex])
                continue;

            if (dominoes[currIndex] == '.' && timeLeft[currIndex] == timeRight[currIndex])
            {
                ans[currIndex] = '.';
                continue;
            }
            
            int neigh = currSide == 'L' ? currIndex-1 : currIndex+1;
            int newTime = currTime+1;
            ans[currIndex] = currSide;

            if (neigh < 0 || neigh == size)
                continue;

            if (currSide == 'L' && timeLeft[neigh] > newTime){
                minHeap.push({newTime, neigh, 'L'});
                timeLeft[neigh] = newTime;
            }
            else if(currSide == 'R' && timeRight[neigh] > newTime){
                minHeap.push({newTime, neigh, 'R'});
                timeRight[neigh] = newTime;
            }
        }         
        return ans;
    }
};