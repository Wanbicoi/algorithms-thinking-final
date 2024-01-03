#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

pair<int,int> find_closest(vector<pair<int,int>> &arr, int left, int right, int target){
    if (left == right) 
        return arr[left];

    int mid = (left + right) / 2;

    auto leftClosest = find_closest(arr, left, mid, target);
    auto rightClosest = find_closest(arr, mid + 1, right, target);

    if (abs(leftClosest.first - target) <= abs(rightClosest.first - target)) {
        return leftClosest;
    }
    else {
        return rightClosest;
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<pair<int, int>> a(m);
    vector<pair<int, int>> b(n);

    for (int i = 0; i < m; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i + 1;
    }

    sort(a.begin(), a.end());
    int min_diff = INT_MAX;
    int res_a, res_b;
    cout << endl;
    for(int i = 0; i < n; i++){
        auto found_val = find_closest(a, 0, m - 1, -b[i].first);
        if(min_diff > abs(found_val.first + b[i].first)){
            min_diff = abs(found_val.first + b[i].first);
            res_a = found_val.second;
            res_b = i + 1;
        }
    }
    cout << res_a << " " << res_b << endl;

    return 0;
}
