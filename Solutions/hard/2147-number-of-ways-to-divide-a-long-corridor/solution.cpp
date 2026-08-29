using ll = long long;
class Solution {
public:
    int numberOfWays(string corridor) {
        vector<ll> seats;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < corridor.size(); ++i) {
            if(corridor[i] == 'S')
                seats.push_back(i);
        }
        
        if(seats.size() < 2 || seats.size() & 1)
            return 0;

        ll res = 1;
        
        for (int i = 1; i < seats.size() - 1; i+=2) {
            res = (res * (seats[i+1] - seats[i])) % MOD;
        }

        return res;
    }
};