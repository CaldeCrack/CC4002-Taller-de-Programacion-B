// https://vjudge.net/contest/578793#problem/B
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isValid (vector<ll> arr ,int n, int k, ll mid) {
    int count = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid)
            return false;
        if (sum + arr[i] > mid) {
            count++;
            sum = 0;
        }
        sum += arr[i];
    }
    if (sum > 0)
        count++;
    return count <= k;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ll lo = 1, hi = 1e18;
    while (lo < hi) {
        ll mid = (lo + hi) >> 1;
        if (isValid(arr, n, k, mid)) {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}