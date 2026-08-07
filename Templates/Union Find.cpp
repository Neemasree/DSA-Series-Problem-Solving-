#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    vector<int> parent, size;

public:
    explicit UnionFind(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};
