class Solution {
private:
    int getStatus(int cnt_a, int cnt_b) {
        return ((cnt_a & 1) << 1) | (cnt_b & 1);
    }

public:
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        int D = 5; 

        for (char a = '0'; a < '0' + D; ++a) {
            for (char b = '0'; b < '0' + D; ++b) {
                if (a == b) continue;

                vector<int> best(4, INT_MAX);
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;

                for (int right = 0; right < n; ++right) {
                    if (s[right] == a) cnt_a++;
                    if (s[right] == b) cnt_b++;

                    while (right - left >= k && (cnt_b - prev_b) >= 2) {
                        int status = getStatus(prev_a, prev_b);
                        best[status] = min(best[status], prev_a - prev_b);

                        left++;
                        if (s[left] == a) prev_a++;
                        if (s[left] == b) prev_b++;
                    }

                    int status_right = getStatus(cnt_a, cnt_b);
                    int required_status = status_right ^ 0b10;

                    if (best[required_status] != INT_MAX) {
                        int diff = (cnt_a - cnt_b) - best[required_status];
                        ans = max(ans, diff);
                    }
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};