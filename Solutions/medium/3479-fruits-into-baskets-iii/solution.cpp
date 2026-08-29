const int INF = -1;

struct SegmentTree {
    int n;
    vector<int> tree; // guarda o máximo capacity do segmento

    SegmentTree(const vector<int>& baskets) {
        n = (int)baskets.size();
        tree.resize(4*n, -1);
        build(baskets, 0, 0, n-1);
    }

    void build(const vector<int>& baskets, int node, int l, int r) {
        if (l == r) {
            tree[node] = baskets[l];
            return;
        }
        int mid = (l+r)/2;
        build(baskets, 2*node+1, l, mid);
        build(baskets, 2*node+2, mid+1, r);
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    void update(int node, int l, int r, int i, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if (i <= mid) update(2*node+1, l, mid, i, val);
        else update(2*node+2, mid+1, r, i, val);
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    // Retorna o menor índice com capacity >= val
    int query(int node, int l, int r, int val) {
        if (tree[node] < val) return -1;
        if (l == r) return l;
        int mid = (l+r)/2;
        int leftRes = query(2*node+1, l, mid, val);
        if (leftRes != -1) return leftRes;
        return query(2*node+2, mid+1, r, val);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree seg(baskets);
        int unplaced = 0;

        for (int fruit : fruits) {
            int idx = seg.query(0, 0, n-1, fruit);
            if (idx == -1) {
                ++unplaced;
            } else {
                seg.update(0, 0, n-1, idx, -1); // marca como usado, capacidade inválida
            }
        }
        return unplaced;
    }
};