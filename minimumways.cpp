#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
  if (n == 1)
    return 0;
  if (n == 2 || n == 3)
    return 1;

  return 1 + min({f(n - 1), (n % 2 == 0) ? f(n / 2) : INT_MAX, (n % 3 == 0) ? f(n / 3) : INT_MAX});
}

int main()
{
  int n;
  cin >> n;
  cout << f(n);

  return 0;
}