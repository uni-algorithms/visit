#ifndef VISIT_HPP
#define VISIT_HPP

#include <algorithm>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

typedef int node;
typedef unordered_map<node, unordered_set<node>> graph;

void add_node(graph &g, const node &n) {
    g.emplace(n, unordered_set<node>());
}

void add_arch(graph &g, const node &a, const node &b) {
    g.find(a)->second.insert(b);
}

unsigned long dfs(const graph &g, unordered_set<node> &visited, const node &n) {
    auto ns = g.find(n)->second;
    vector<node> news;
    copy_if(begin(ns), end(ns), back_inserter(news), [&visited](const node &a) { return visited.insert(a).second; });
    for (auto u : news) { dfs(g, visited, u); }
    return visited.size();
}

unsigned long dfs(const graph &g, const node &n) {
    unordered_set<node> just_n = {n};
    return g.empty() ? just_n.size() : dfs(g, just_n, n);
}

void from_stream(graph &g, istream &input, const unsigned long nodes, const unsigned long arches) {
    for (node n = 0; n < nodes; n++) {
        add_node(g, n);
    }

    for (auto i = 0; i < arches; i++) {
        node a;
        node b;

        input >> a >> b;
        add_arch(g, a, b);
    }
}

unsigned long visit(istream &input) {
    unsigned long n;
    unsigned long m;
    node s;

    input >> n >> m >> s;
    graph g;
    from_stream(g, input, n, m);
    return dfs(g, s);
}

#endif //VISIT_HPP
