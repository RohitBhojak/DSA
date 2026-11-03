#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

class FenwickTree
{
  int n;
  vi tree, nums;

public:
  FenwickTree(const vi &arr)
  {
    n = (int)arr.size();
    tree.assign(n + 1, 0);
    nums.assign(n + 1, 0);

    copy(arr.begin(), arr.end(), nums.begin() + 1);
    copy(arr.begin(), arr.end(), tree.begin() + 1);

    for (int i = 1; i <= n; i++)
    {
      int next = i + (i & -i);
      if (next <= n)
        tree[next] += tree[i];
    }
  }

  void update(int idx, int val)
  {
    int i = idx + 1;
    int diff = val - nums[i];
    nums[i] = val;

    while (i <= n)
    {
      tree[i] += diff;
      i += i & -i;
    }
  }

  // Sum of range [0, range]
  int sum(int range)
  {
    int sum = 0;
    int i = range + 1;
    while (i > 0)
    {
      sum += tree[i];
      i -= i & -i;
    }
    return sum;
  }
};