// https://vjudge.net/contest/576664#problem/E
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n; cin >> x >> n;
	vector<int> positions(n);
	for (int i = 0; i < n; i++)
        cin >> positions[i];
	set<int> lights{0, x};
	for (int i : positions)
        lights.insert(i);
	vector<int> distances(n);
	int prev = 0, max_distance = 1;
	for (int i : lights) {
		max_distance = max(max_distance, i - prev);
		prev = i;
	}
	distances[n-1] = max_distance;
	for (int i = n - 1; i > 0; i--) {
		lights.erase(positions[i]);
		auto top = lights.upper_bound(positions[i]);
		int upper = *top, lower = *(--top);
		max_distance = max(max_distance, upper - lower);
		distances[i-1] = max_distance;
	}
	for (int i : distances)
        cout << i << " ";
    return 0;
}