using ll = long long;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<ll> pq(target.begin(), target.end());
        ll total = accumulate(target.begin(), target.end(), 0LL);

        while (true) {
            ll curr = pq.top();
            pq.pop();

            ll rest = total - curr;
            if (curr == 1 || rest == 1) return true;      // caso final

            if (rest == 0 || curr < rest) return false;   // inválido

            ll prev = curr % rest;                        // pulo por módulo
            if (prev == 0) prev = rest;

            if (prev == curr) return false;               // não reduz, então loop infinito

            total = rest + prev;
            pq.push(prev);
        }
    }
};
