#include <bits/stdc++.h>
using namespace std;
vector<int> dp(1000005, -1);
vector<int> get_digit(int n)
{
  vector<int> d;
  while (n > 0)
  {
    if (n % 10 != 0)
    {
      d.push_back(n % 10);
    }
    n = n / 10;
  }
  return d;
}

int f(int n)
{
  if (n == 0)
    return 0;
  if (n <= 9)
    return 1;
  int result = INT_MAX;
  if (dp[n] != -1)
    return dp[n];
  vector<int> d = get_digit(n);
  for (int i = 0; i < d.size(); i++)
  {
    result = min(result, f(n - d[i]));
  }
  return dp[n] = result + 1;
}

int main()
{
  int n;
  cin >> n;
  cout << f(n);
  return 0;
}