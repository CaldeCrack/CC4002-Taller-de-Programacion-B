// https://vjudge.net/contest/583647#problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, x; cin >> n >> x;
    vector<int> miradores(n), dp(n, 1);
    for (int i = 0; i < n; i++)
        cin >> miradores[i];
    for (int i = n - 2; i >= 0; i--) {
        if (miradores[i+1] - miradores[i] <= x)
            dp[i] = dp[i+1] + 1;
    }
    int max = *max_element(dp.begin(), dp.end());
    cout << max << endl;
}