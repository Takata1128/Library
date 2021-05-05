#include <bits/stdc++.h>
using namespace std;

// Trie木
// 参考：https://algo-logic.info/trie-tree/
// 挿入、検索ともにO(|文字列の長さ|)
template <int char_size, int base> struct Trie {
    struct Node {
        vector<int> next; //子の頂点のインデックス
        int last;         // 終端する単語数
        int count;        // Nodeを共有する単語数
        Node() : count(0), last(0) { next.assign(char_size, -1); }
    };
    vector<Node> nodes; // Trie木本体
    Trie() { nodes.push_back(Node(0)); }

    // 単語の挿入
    void insert(const string &word) {
        int node_idx = 0;
        for(int i = 0; i < word.size(); i++) {
            int c = word[i] - base;
            int next_idx = nodes[node_idx].next[c];
            if(next_idx == -1) {
                next_idx = nodes.size();
                nodes.push_back(Node());
            }
            nodes[node_idx].count++;
            node_idx = next_idx;
        }
        nodes[node_idx].count++;
        nodes[node_idx].last++;
    }

    // 単語の検索（数を返す）
    int search_count(const string &word, bool prefix = false) {
        int node_idx = 0;
        for(int i = 0; i < word.size(); i++) {
            int c = word[i] - base;
            int next_idx = nodes[node_idx].next[c];
            if(next_idx == -1) {
                return 0;
            }
            node_idx = next_idx;
        }
        return prefix ? nodes[node_idx].count : nodes[node_idx].last;
    }

    // prefixを持つ単語の検索（数を返す）
    int prefix_count(const string &prefix) {
        return search_count(prefix, true);
    }

    int word_count() { return nodes[0].count; }

    int size() { return nodes.size(); }
};