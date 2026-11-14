#include <bits/stdc++.h>

using namespace std;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9;

class Dijkstra
{
    int n; // vertices
    int m; // edges
    vector<vector<pair<int, int>>> adjList;
    vector<int> dist;

public:
    Dijkstra(int n, int m, vector<vector<pair<int, int>>> &adjList)
    {
        this->n = n;
        this->m = m;
        this->adjList = adjList;
        dist.assign(n + 1, INF); // 1-based indexing
    }

    vector<int> findDistance(int src)
    {
        min_heap<pair<int, int>> pq; // min heap of {weight, node} pairs

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            // Optimization: Early return if target node is reached
            // if (u == target) return dist[u];

            for (auto [v, w] : adjList[u])
            {
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};