using ll = long long;

class Solution {
public:
    // A substring [s_i, s_j] is valid if the state is the same at i and j.
    // state = freq_a - freq_b == freq_b - freq_c at point s_i and s_j 
    int longestBalanced(string s) {
        const int n = s.size();
        
        int case_1 = 1, curr = 1;
        char last = s[0];
        
        // Case 1: longest sequence of a single letter
        for(int i = 1; i < n; ++i){
            if(last == s[i])
                ++curr;
            else{
                curr = 1;
                last = s[i];
            }
            case_1 = max(case_1, curr);
        }
        
        // Case 2: longest balanced two letter substr, more difficult than case 3
        constexpr array<pair<char,char>, 3> pairs = {{
            {'a', 'b'},
            {'a', 'c'},
            {'b', 'c'}
        }};
        
        int case_2 = 0;
        curr = 0;
        for(const auto& [l1, l2] : pairs){
            int freq_1 = 0, freq_2 = 0;
            unordered_map<int, int> states_2;
            states_2[0] = -1;
            
            for(int i = 0; i < n; ++i){
                if(l1 != s[i] && l2 != s[i]){
                    states_2.clear();
                    freq_1 = freq_2 = 0;
                    states_2[0] = i;
                    continue;
                }
                else if(s[i] == l1)
                    ++freq_1;
                else
                    ++freq_2;

                int diff = freq_1 - freq_2;

                auto it = states_2.find(diff);
                if(it != states_2.end())
                    case_2 = max(case_2, i - it->second);
                else
                    states_2[diff] = i;
            } 
        }
        
        // Case 3: longest balanced three letter substr
        unordered_map<ll, int> states_3; // {state, last pos}
        
        auto key = [](int a, int b){
            return ( (ll)(unsigned int)a << 32 )
            | (unsigned int)b;
        };
        
        states_3[key(0,0)] = -1;

        int case_3 = 0;

        int freq_a = 0, freq_b = 0, freq_c = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == 'a')
                ++freq_a;
            else if(s[i] == 'b')
                ++freq_b;
            else
                ++freq_c;

            int state1 = freq_a - freq_b;
            int state2 = freq_a - freq_c;
            
            ll k = key(state1, state2);

            auto it = states_3.find(k);
            if(it != states_3.end())
                case_3 = max(case_3, i - it->second);
            else
                states_3[k] = i;
            
        }

        return max({case_1, case_2, case_3});
    }
};