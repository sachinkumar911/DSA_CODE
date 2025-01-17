#include <bits/stdc++.h>
using namespace std;

void f(int ind, vector<int> &ans, vector<int> arr)
{
  if (ind >= arr.size())
  {
    for (int it : ans)
    {
      cout << it << " ";
    }
    if (ans.size() == 0)
    {
      cout << "{}";
    }
    cout << endl;
    return;
  }

  // take the current index element
  ans.push_back(arr[ind]);
  f(ind + 1, ans, arr);
  ans.pop_back();
  // not take the current index element
  f(ind + 1, ans, arr);
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    arr.push_back(x);
  }
  vector<int> ans;
  f(0, ans, arr);
  return 0;
}