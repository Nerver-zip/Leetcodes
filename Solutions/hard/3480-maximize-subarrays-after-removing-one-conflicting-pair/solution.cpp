class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<pair<int, int>>> startEvents(n + 2);  // startEvents[i] = list of (b, idx)
        for (int idx = 0; idx < conflictingPairs.size(); ++idx) {
            int a = conflictingPairs[idx][0];
            int b = conflictingPairs[idx][1];
            if (a > b) swap(a, b);
            startEvents[a].emplace_back(b, idx);
        }

        vector<int> firstBlockingPos(n + 2, n);
        vector<int> secondBlockingPos(n + 2, n);
        vector<int> idxBlocking(n + 2, -1);

        multiset<pair<int, int>> activeConflicts;
        long long validCnt = 0;
        unordered_map<int, long long> cand;

        for (int i = n; i >= 1; --i) {
            // Adiciona novos conflitos ativos que começam em i
            for (auto& [b, idx] : startEvents[i]) {
                activeConflicts.insert({b, idx});
            }

            // Remove conflitos expirados
            while (!activeConflicts.empty() && activeConflicts.begin()->first <= i) {
                activeConflicts.erase(activeConflicts.begin());
            }

            if (activeConflicts.empty()) {
                firstBlockingPos[i] = secondBlockingPos[i] = n;
                idxBlocking[i] = -1;
            } else {
                auto it = activeConflicts.begin();
                int b1 = it->first, idx1 = it->second;
                firstBlockingPos[i] = b1 - 1;
                idxBlocking[i] = idx1;

                ++it;
                if (it != activeConflicts.end()) {
                    secondBlockingPos[i] = it->first - 1;
                } else {
                    secondBlockingPos[i] = n;
                }
            }

            int len = firstBlockingPos[i] - i + 1;
            if (len > 0) validCnt += len;

            int gain = secondBlockingPos[i] - firstBlockingPos[i];
            if (idxBlocking[i] != -1 && gain > 0)
                cand[idxBlocking[i]] += gain;
        }

        long long extra = 0;
        for (auto& [idx, val] : cand) {
            extra = max(extra, val);
        }

        return validCnt + extra;
    }
};