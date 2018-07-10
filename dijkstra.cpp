#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;

int n;
vector<pair<int, ll>> *adj;
ll *d;

void dijkstra(int start, vector<pair<int, ll>> *adj, ll *d) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> PQ;
    for (int i = 0; i < n + 1; i++) {
        d[i] = LLONG_MAX;
    }
    d[start] = 0;

    PQ.push(make_pair(0, start));
    while (!PQ.empty()) {
        pair<ll, int> f = PQ.top();
        PQ.pop();
        int u = f.second;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (d[u] + adj[u][i].second < d[v]) {
                d[v] = d[u] + adj[u][i].second;
                PQ.push(make_pair(d[v], v));
            }
        }
    }
}