// https://vjudge.net/contest/583647#problem/B

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<bool>> grid(n, vector<bool>(n, true));
    vector<vector<ll>> paths(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == '*')
                grid[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!grid[i][0])
            break;
        paths[i][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (!grid[0][i])
            break;
        paths[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (!grid[i][j])
                continue;
            paths[i][j] = paths[i-1][j] + paths[i][j-1];
        }
    }
    cout << paths[n-1][n-1] % 1000000007 << endl;
}