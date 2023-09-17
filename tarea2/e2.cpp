// https://vjudge.net/contest/578793#problem/E
#include <bits/stdc++.h>
using namespace std;

bool check(vector<double> trees, double mid, int n, int m) {
    int cnt = 1;
    double prevDist = trees[0] + mid;
    for (int i = 1; i < m; i++) {
        double nextDist = trees[i] - prevDist;
        if (nextDist > mid) {
            cnt++;
            prevDist = trees[i] + mid;
        }
    }
    return cnt <= n;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<double> trees(m);
        for (int i = 0; i < m; i++)
            cin >> trees[i];
        sort(trees.begin(), trees.end());
        double izq = 0, der = 1000000;
        while (der - izq > 1e-9) {
            double mid = (izq + der) / 2.0;
            if (check(trees, mid, n, m))
                der = mid;
            else
                izq = mid;
        }
        cout << fixed << setprecision(1) << izq << endl;
    }
}