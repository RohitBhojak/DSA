#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

class BellmanFord
{
    int n; // vertices
    int m; // edges
    vector<tuple<int, int, int>> edgeList;
    vector<int> dist;

public:
    BellmanFord(int n, int m, vector<tuple<int, int, int>> &edgeList)
    {
        this->n = n;
        this->m = m;
        this->edgeList = edgeList;
        dist.assign(n + 1, INF); // 1-based indexing
    }

    vector<int> findDistance(int src)
    {
        dist[src] = 0;
        // Negative cycle check: Run 1 extra iteration, if any distance changes then negative cycle is present
        for (int i = 0; i < n - 1; i++)
        {
            for (auto [w, u, v] : edgeList)
            {
                // Optimization: Early return when no distance is updated in an iteration
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
        return dist;
    }
};
