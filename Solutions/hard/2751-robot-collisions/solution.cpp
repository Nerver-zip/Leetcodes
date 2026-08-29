class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        const int n = positions.size();
        vector<int> order(n, 0);        
            
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](const auto& a, const auto& b){
            return positions[a] < positions[b];
        });
        
        stack<int> s; // stores access index of R

        for(int i : order){
            if(directions[i] == 'R'){
                s.push(i);
            }
            else{
                while(!s.empty()){
                    int r_idx = s.top();
                    
                    int& r_health = healths[r_idx];
                    int& l_health = healths[i];
                    
                    if(r_health > l_health){
                        --r_health; // dec R, set L health to 0 and move on
                        l_health = 0;
                        break;
                    }
                    else if(r_health < l_health){
                        --l_health; // dec L health
                        r_health = 0; // pop R
                        s.pop();
                    }
                    else{
                        l_health = 0;
                        r_health = 0;
                        s.pop();
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        for(int h : healths)
            if(h)
                ans.push_back(h);

        return ans;
    }
};