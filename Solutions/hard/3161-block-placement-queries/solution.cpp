struct SegTree {
    int n;
    vector<int> seg;

    SegTree(int n): n(n) {
        seg.assign(4*n, 0);
    }

    void update(int idx, int val, int p, int l, int r) {
        if (l == r) {
            seg[p] = val;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid) update(idx, val, p*2, l, mid);
        else update(idx, val, p*2+1, mid+1, r);

        seg[p] = max(seg[p*2], seg[p*2+1]);
    }

    void update(int idx, int val) {
        update(idx, val, 1, 0, n);
    }

    int query(int L, int R, int p, int l, int r) {
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return seg[p];

        int mid = (l + r) / 2;
        return max(
            query(L, R, p*2, l, mid),
            query(L, R, p*2+1, mid+1, r)
        );
    }

    int query(int L, int R) {
        if (L > R) return 0;
        return query(L, R, 1, 0, n);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MX = 50000;

        set<int> st;
        st.insert(0);
        st.insert(MX);

        SegTree seg(MX);

        // inicial: um único intervalo [0, MX]
        seg.update(MX, MX);

        vector<bool> ans;

        for (auto &q : queries) {
            if (q[0] == 1) {
                int x = q[1];

                auto it = st.lower_bound(x);
                int r = *it;
                int l = *prev(it);

                // remove old interval (l, r)
                seg.update(r, 0);

                st.insert(x);

                // add new intervals
                seg.update(x, x - l);
                seg.update(r, r - x);
            } 
            else {
                int x = q[1], sz = q[2];

                auto it = st.upper_bound(x);
                int pre = *prev(it);

                int best_inside = seg.query(0, pre);
                int best_border = x - pre;

                ans.push_back(max(best_inside, best_border) >= sz);
            }
        }

        return ans;
    }
};