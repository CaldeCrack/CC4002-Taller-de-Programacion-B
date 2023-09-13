// https://vjudge.net/contest/578793#problem/A
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    ll n, t; cin >> n >> t;
    vector<ll> times(n);
    for (ll i = 0; i < n; i++)
        cin >> times[i];
    ll minTime = 0, maxTime = 1e18, ans = 0;
    while (minTime <= maxTime) {
        ll midTime = (minTime + maxTime) >> 1;
        ll fracSum = 0;
		for (ll i = 0; i < n; i++) {
			fracSum += midTime / times[i];
			if (fracSum >= t) {
				break;
			}
		}
        if (fracSum >= t) {
            ans = midTime;
            maxTime = midTime - 1;
        }
        else
            minTime = midTime + 1;
    }
    cout << ans << endl;
    return 0;
}