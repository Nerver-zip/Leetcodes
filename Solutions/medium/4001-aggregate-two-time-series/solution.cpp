class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        const int m = series1.size();
        const int n = series2.size(); 
        vector<vector<int>> ans;
        
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;

        for(int i = 0; i < m; ++i){
            q1.push({series1[i][0], series1[i][1]});
        }

        for(int j = 0; j < n; ++j){
            q2.push({series2[j][0], series2[j][1]});
        }

        while(!q1.empty() && !q2.empty()){
            auto [tstamp1, v1] = q1.front();
            auto [tstamp2, v2] = q2.front();

            
            if(tstamp1 == tstamp2){

                ans.push_back({tstamp1, v1 + v2});
                q1.pop();
                q2.pop();
            }
            else if(tstamp1 < tstamp2){
                ans.push_back({tstamp1, v1 + v2});
                q1.pop();
            }
            else{
                ans.push_back({tstamp2, v1 + v2});
                q2.pop();
            }
        }

        while(!q1.empty()){
            auto [tstamp1, v1] = q1.front();
            ans.push_back({tstamp1, v1});
            q1.pop();
        }


        while(!q2.empty()){
            auto [tstamp2, v2] = q2.front();
            ans.push_back({tstamp2, v2});
            q2.pop();
        }

        return ans;
    }
};