#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

// For range sum and point update
class SegmentTree
{
  int n;
  vi tree;

public:
  SegmentTree(vi &arr)
  {
    n = (int)arr.size();
    tree.assign(n << 1, 0);
    copy(arr.begin(), arr.end(), tree.begin() + n);

    for (int i = n - 1; i > 0; i--)
    {
      tree[i] = tree[i << 1] + tree[(i << 1) + 1];
    }
  }

  void update(int idx, int val)
  {
    int i = idx + n;
    tree[i] = val;
    for (i >>= 1; i > 0; i >>= 1)
    {
      tree[i] = tree[i << 1] + tree[(i << 1) + 1];
    }
  }

  // Inclusive range [left, right]
  int sum(int left, int right)
  {
    left += n, right += n;
    int sum = 0;
    while (left <= right)
    {
      if ((left & 1) == 1)
        sum += tree[left++];
      if ((right & 1) == 0)
        sum += tree[right--];
      left >>= 1, right >>= 1;
    }
    return sum;
  }
};