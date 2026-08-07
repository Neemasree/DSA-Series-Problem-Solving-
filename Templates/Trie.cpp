#include <bits/stdc++.h>
using namespace std;

class Trie {
    struct Node {
        array<int, 26> next{};
        bool terminal = false;
        Node() { next.fill(-1); }
    };

    vector<Node> nodes{1};

public:
    void insert(const string& word) {
        int current = 0;
        for (char ch : word) {
            int index = ch - 'a';
            if (nodes[current].next[index] == -1) {
                nodes[current].next[index] = static_cast<int>(nodes.size());
                nodes.emplace_back();
            }
            current = nodes[current].next[index];
        }
        nodes[current].terminal = true;
    }
};
