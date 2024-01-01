#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

int main()
{
    fastio;
    vector<int> arr;
    string s;
    while (getline(cin, s, ',')){
        arr.push_back(stoi(s));
    }

    int n = arr.size();
    int total = 0;
    int max_left = INT_MIN, max_right = INT_MIN;
    int left = 0, right = n - 1;
    while(left < right){
        max_left = max(max_left, arr[left]);
        max_right = max(max_right, arr[right]);
        if(max_left < max_right)
        {
            total += max_left - arr[left];
            left++;
        }
        else{
            total += max_right - arr[right];
            right--;
        }

    }

    cout << total << '\n';
    return 0;
}
