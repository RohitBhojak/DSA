#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

class FloydWarshall
{
    int n;
    vector<vector<int>> matrix;
    vector<vector<int>> dist;

public:
    FloydWarshall(int n, vector<vector<int>> &matrix)
    {
        this->n = n; // vertices
        this->matrix = matrix;
        dist.assign(n + 1, vector<int>(n + 1, INF)); // 1-based indexing
    }

    vector<vector<int>> findDistance()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
                else if (matrix[i][j])
                {
                    dist[i][j] = matrix[i][j];
                }
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        return dist;
    }
};