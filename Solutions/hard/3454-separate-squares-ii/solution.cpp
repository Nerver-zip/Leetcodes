struct Event {
    double y;
    int x1, x2;
    int type; // +1 add, -1 remove
    bool operator<(const Event& e) const {
        return y < e.y;
    }
};

struct SegTree {
    int n;
    vector<int> cnt;
    vector<double> len;
    vector<double> xs;

    SegTree(int n, vector<double>& xs) : n(n), xs(xs) {
        cnt.assign(4*n, 0);
        len.assign(4*n, 0);
    }

    void pull(int node, int l, int r) {
        if (cnt[node] > 0) {
            len[node] = xs[r] - xs[l];
        } else if (l + 1 == r) {
            len[node] = 0;
        } else {
            len[node] = len[node*2] + len[node*2+1];
        }
    }

    void update(int node, int l, int r, int ql, int qr, int v) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            cnt[node] += v;
            pull(node, l, r);
            return;
        }
        int m = (l+r)/2;
        update(node*2, l, m, ql, qr, v);
        update(node*2+1, m, r, ql, qr, v);
        pull(node, l, r);
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& sq) {
        vector<double> xs;
        vector<Event> ev;
        for (auto& s: sq) {
            double x = s[0], y = s[1], l = s[2];
            xs.push_back(x);
            xs.push_back(x+l);
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        auto getX = [&](double v){
            return lower_bound(xs.begin(), xs.end(), v) - xs.begin();
        };

        for (auto& s: sq) {
            double x = s[0], y = s[1], l = s[2];
            ev.push_back({
            y,
            (int)getX(x),
            (int)getX(x + l),
            +1
            });
            
            ev.push_back({
            y + l,
            (int)getX(x),
            (int)getX(x + l),
            -1
            });
        }

        sort(ev.begin(), ev.end());
        SegTree st(xs.size(), xs);

        double totalArea = 0;
        for (int i = 0; i + 1 < ev.size(); i++) {
            st.update(1, 0, st.n, ev[i].x1, ev[i].x2, ev[i].type);
            double dy = ev[i+1].y - ev[i].y;
            totalArea += st.len[1] * dy;
        }

        double half = totalArea / 2;
        double cur = 0;
        st = SegTree(xs.size(), xs);

        for (int i=0;i+1<ev.size();i++) {
            st.update(1,0,st.n, ev[i].x1, ev[i].x2, ev[i].type);
            double dy = ev[i+1].y - ev[i].y;
            double area = st.len[1] * dy;
            if (cur + area >= half) {
                return ev[i].y + (half - cur) / st.len[1];
            }
            cur += area;
        }
        return 0;
    }
};