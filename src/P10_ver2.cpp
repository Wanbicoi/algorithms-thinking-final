#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int mask = 1; mask < (1 << 9); mask++) {
    bitset<9> mask_set(mask);                   // Số -> 1 chuỗi nhị phân
    int cur = stoi(mask_set.to_string());       // O(9)
    if (cur % n == 0) {
      cout << cur << '\n';
      return 0;
    }
  } // O(9*2^9)

  cout << -1 << endl;
  return 0;
}
