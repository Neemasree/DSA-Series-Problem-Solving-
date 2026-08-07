#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    int n;
    vector<long long> tree;

    void update(int node, int left, int right, int index, long long value) {
        if (left == right) {
            tree[node] = value;
            return;
        }
        int mid = left + (right - left) / 2;
        if (index <= mid) update(node * 2, left, mid, index, value);
        else update(node * 2 + 1, mid + 1, right, index, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

public:
    explicit SegmentTree(int size) : n(size), tree(size * 4, 0) {}

    void update(int index, long long value) { update(1, 0, n - 1, index, value); }
};
