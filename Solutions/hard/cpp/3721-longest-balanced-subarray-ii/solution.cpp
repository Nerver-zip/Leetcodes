class SegTree {
public:
    struct Node {
        int mn, mx, lazy;
    };

    int n;
    vector<Node> tree;

    SegTree(int size) {
        n = size;
        tree.resize(4*n);
    }

    void push(int node) {
        if (tree[node].lazy != 0) {
            int val = tree[node].lazy;
            for (int child : {node*2, node*2+1}) {
                tree[child].mn += val;
                tree[child].mx += val;
                tree[child].lazy += val;
            }
            tree[node].lazy = 0;
        }
    }

    void build(int node, int l, int r, vector<int>& arr) {
        if (l == r) {
            tree[node].mn = tree[node].mx = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(node*2, l, mid, arr);
        build(node*2+1, mid+1, r, arr);
        tree[node].mn = min(tree[node*2].mn, tree[node*2+1].mn);
        tree[node].mx = max(tree[node*2].mx, tree[node*2+1].mx);
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            tree[node].mn += val;
            tree[node].mx += val;
            tree[node].lazy += val;
            return;
        }
        push(node);
        int mid = (l+r)/2;
        update(node*2, l, mid, ql, qr, val);
        update(node*2+1, mid+1, r, ql, qr, val);
        tree[node].mn = min(tree[node*2].mn, tree[node*2+1].mn);
        tree[node].mx = max(tree[node*2].mx, tree[node*2+1].mx);
    }

    int findRightmostZero(int node, int l, int r, int ql) {
        if (r < ql) return -1;
        if (tree[node].mn > 0 || tree[node].mx < 0) return -1;
        if (l == r) return l;
        push(node);
        int mid = (l+r)/2;
        int right = findRightmostZero(node*2+1, mid+1, r, ql);
        if (right != -1) return right;
        return findRightmostZero(node*2, l, mid, ql);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, queue<int>> pos;

        for (int i = 0; i < n; i++)
            pos[nums[i]].push(i);

        vector<int> pref(n);
        unordered_set<int> seen;
        int cur = 0;

        for (int i = 0; i < n; i++) {
            if (!seen.count(nums[i])) {
                seen.insert(nums[i]);
                cur += (nums[i] % 2 == 0 ? 1 : -1);
            }
            pref[i] = cur;
        }

        SegTree seg(n);
        seg.build(1, 0, n-1, pref);

        int ans = 0;

        for (int left = 0; left < n; left++) {

            int r = seg.findRightmostZero(1, 0, n-1, left + ans);
            if (r != -1)
                ans = max(ans, r - left + 1);

            int val = (nums[left] % 2 == 0 ? 1 : -1);
            pos[nums[left]].pop();

            int next = pos[nums[left]].empty() ? n : pos[nums[left]].front();

            seg.update(1, 0, n-1, left, next-1, -val);
        }

        return ans;
    }
};
