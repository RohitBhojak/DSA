#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

class TreeDiameter
{
  vector<vi> adj;

public:
  TreeDiameter(vector<vi> &adj)
  {
    this->adj = adj;
  }

  // Using Double DFS

  pii dfs(int node, int parent)
  {
    pii result = {0, node};
    for (auto child : adj[node])
    {
      if (child == parent)
        continue;
      pii ret = dfs(child, node);
      result = max(result, {ret.first + 1, ret.second});
    }
    return result;
  };

  int doubleDfs()
  {
    int node = dfs(1, -1).second;
    return dfs(node, -1).first;
  }

  // Using DP

  void dfs(int node, int parent, vi &dist, int &diameter)
  {
    for (int child : adj[node])
    {
      if (child == parent)
        continue;
      dfs(child, node, dist, diameter);
      diameter = max(diameter, dist[node] + dist[child] + 1);
      dist[node] = max(dist[node], dist[child] + 1);
    }
  };

  int dp()
  {
    vi dist(adj.size() + 1, 0);
    int diameter = 0;
    dfs(1, -1, dist, diameter);
    return diameter;
  }
};