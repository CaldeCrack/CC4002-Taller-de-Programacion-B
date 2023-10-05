// https://vjudge.net/contest/583647#problem/E
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, a, b, c, pieces = 0;
	cin >> n >> a >> b >> c;
	for (int i = 0; i*a <= n; ++i) {
		for (int j = 0; i*a + j*b <= n; ++j) {
			int k = (n - i*a - j*b) / c;
			if (i*a + j*b + k*c == n)
                pieces = max(i + j + k, pieces);
		}
	}
	cout << pieces <<"\n";
}