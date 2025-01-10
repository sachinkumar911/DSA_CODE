#include <bits/stdc++.h>
using namespace std;
vector<int> coin;
vector<int> dp(1000006, -1);
int f(int n)
{
  if (n == 0)
    return 0;
  int result = INT_MAX;
  if (dp[n] != -1)
    return dp[n];
  for (int i = 0; i < coin.size(); i++)
  {
    if (n - coin[i] < 0)
      continue;
    result = min(result, f(n - coin[i]));
  }
  if (result == INT_MAX)
    return dp[n] = INT_MAX;
  return dp[n] = 1 + result;
}

int main()
{
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    coin.push_back(x);
  }

  int ans = f(t);
  if (ans == INT_MAX)
    cout << -1 << "\n";
  else
    cout << ans << endl;
  return 0;
}