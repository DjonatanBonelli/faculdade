#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> sizeMap = {
    {"XXL", 0}, {"XL", 1}, {"L", 2},
    {"M", 3}, {"S", 4}, {"XS", 5}
};

const int MAXN = 36;
const int MAXM = 30;
const int MAXS = 6;

vector<int> adj[MAXN];
int pairU[MAXM], pairV[MAXS], dist[MAXM + 1];
bool used[MAXM], vis[MAXM];

bool bfs(int M) {
    queue<int> Q;
    for (int u = 0; u < M; ++u) {
        if (!used[u]) {
            dist[u] = 0;
            Q.push(u);
        } else {
            dist[u] = INT_MAX;
        }
    }
    dist[M] = INT_MAX;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (dist[u] < dist[M]) {
            for (int v : adj[u]) {
                if (dist[pairV[v]] == INT_MAX) {
                    dist[pairV[v]] = dist[u] + 1;
                    Q.push(pairV[v]);
                }
            }
        }
    }
    return dist[M] != INT_MAX;
}

bool dfs(int u, int M) {
    if (u != M) {
        for (int v : adj[u]) {
            if (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v], M)) {
                pairV[v] = u;
                pairU[u] = v;
                used[u] = true;
                return true;
            }
        }
        dist[u] = INT_MAX;
        return false;
    }
    return true;
}

int hopcroftKarp(int M) {
    fill(pairU, pairU + M, MAXS);
    fill(pairV, pairV + MAXS, M);
    fill(used, used + M, false);

    int matching = 0;
    while (bfs(M)) {
        for (int u = 0; u < M; ++u) {
            if (!used[u] && dfs(u, M)) {
                matching++;
            }
        }
    }
    return matching;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        for (int i = 0; i < M; ++i) {
            adj[i].clear();
        }

        for (int i = 0; i < M; ++i) {
            string size1, size2;
            cin >> size1 >> size2;
            int idx1 = sizeMap[size1];
            int idx2 = sizeMap[size2];
            adj[i].push_back(idx1);
            adj[i].push_back(idx2);
        }

        int maxMatching = hopcroftKarp(M);
        if (maxMatching == M) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
