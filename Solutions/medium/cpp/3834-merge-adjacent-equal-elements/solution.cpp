using ll = long long;
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<ll> st;

        for(ll n : nums){
            while (st.size() > 1) {
                ll n1 = st.top();
                st.pop();
                ll n2 = st.top();
                
                if(n1 == n2){
                    st.pop();
                    st.push(n1 + n2);
                }
                else{
                    st.push(n1);
                    break;
                }
            }
            st.push(n);
        }

        while (st.size() > 1) {
                ll n1 = st.top();
                st.pop();
                ll n2 = st.top();
                
                if(n1 == n2){
                    st.pop();
                    st.push(n1 + n2);
                }
                else{
                    st.push(n1);
                    break;
                }
        }
        
        vector<ll> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};