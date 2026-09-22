class Solution {
    struct Node {
        vector<long long> cnt;
        long long full = 0;
    };

    int k, n;
    vector<Node> tree;

    Node merge(Node& a, Node& b) {
        Node res;
        res.cnt.assign(k, 0);
        for (int v = 0; v < k; v++) res.cnt[v] = a.cnt[v];
        for (int w = 0; w < k; w++) {
            if (b.cnt[w] == 0) continue;
            int target = (int)((a.full * w) % k);
            res.cnt[target] += b.cnt[w];
        }
        res.full = (a.full * b.full) % k;
        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            tree[node].cnt.assign(k, 0);
            int m = nums[l] % k;
            tree[node].cnt[m] = 1;
            tree[node].full = m;
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid, nums);
        build(2*node+1, mid+1, r, nums);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node].cnt.assign(k, 0);
            int m = val % k;
            tree[node].cnt[m] = 1;
            tree[node].full = m;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = merge(tree[2*node], tree[2*node+1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        if (qr <= mid) return query(2*node, l, mid, ql, qr);
        if (ql > mid) return query(2*node+1, mid+1, r, ql, qr);
        Node left = query(2*node, l, mid, ql, qr);
        Node right = query(2*node+1, mid+1, r, ql, qr);
        return merge(left, right);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->k = k;
        n = nums.size();
        tree.assign(4*n, Node());
        build(1, 0, n-1, nums);

        vector<int> result;
        for (auto& q : queries) {
            int index = q[0], value = q[1], start = q[2], x = q[3];
            update(1, 0, n-1, index, value);
            Node res = query(1, 0, n-1, start, n-1);
            result.push_back((int)res.cnt[x]);
        }
        return result;
    }
};