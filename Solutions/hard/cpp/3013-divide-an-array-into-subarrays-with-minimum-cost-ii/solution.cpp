using ll = long long;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int needed = k - 2;

        priority_queue<pair<int,int>, vector<pair<int,int>>, CmpMax> picked;
        priority_queue<pair<int,int>, vector<pair<int,int>>, CmpMin> candidates;

        vector<bool> in_picked(n, false);
        vector<bool> removed(n, false);

        ll sum = 0;
        ll ans = LLONG_MAX;
        int picked_size = 0;

        auto clean = [&]() {
            while (!picked.empty() && removed[picked.top().second])
                picked.pop();
            while (!candidates.empty() && removed[candidates.top().second])
                candidates.pop();
        };

        int right = 2;

        for (int left = 1; left < n; ++left) {

            // adiciona novos candidatos até o limite da janela
            while (right < n && right <= left + dist) {
                candidates.push({nums[right], right});
                right++;
            }

            // remove índice que saiu da janela
            int out = left;
            if (out < n) {
                removed[out] = true;
                if (in_picked[out]) {
                    sum -= nums[out];
                    in_picked[out] = false;
                    picked_size--;
                }
            }

            clean();

            // garante tamanho 
            while (picked_size < needed && !candidates.empty()) {
                auto x = candidates.top();
                candidates.pop();

                picked.push(x);
                sum += x.first;
                in_picked[x.second] = true;
                picked_size++;
            }

            clean();

            // rebalanceamento se o topo do candidato > topo picks
            while (!picked.empty() && !candidates.empty() &&
                   picked.top().first > candidates.top().first) {

                auto a = picked.top(); picked.pop();
                auto b = candidates.top(); candidates.pop();

                sum += b.first - a.first;

                in_picked[a.second] = false;
                in_picked[b.second] = true;

                picked.push(b);
                candidates.push(a);
            }

            if (picked_size == needed) {
                ans = min(ans, 1LL* nums[0] + nums[left] + sum);
            }
        }

        return ans;
    }

private:
    struct CmpMax {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first < b.first;
        }
    };

    struct CmpMin {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first > b.first;        
        }
    };
};