#include <bits/stdc++.h>
using namespace std;

#define fastio                                                                 \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0)

int main(int argc, char *argv[]) {
  fastio;
  int k;
  cin >> k;
  vector<vector<int>> arr(k, vector<int>());
  cin.ignore();
  for (int i = 0; i < k; i++) {
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x)
      arr[i].push_back(x);
  }

  map<int, int> res;
  for (auto row : arr) {
    for (int num : row) {
      if (res.find(num) == res.end())
        res[num] = 1;
      else
        res[num]++;
    }
  }

  for (auto num : res)
    for (int i = 0; i < num.second; i++)
      cout << num.first << " ";

  cout << endl;
  return 0;
}
