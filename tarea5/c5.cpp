// https://vjudge.net/contest/594321#problem/C
// this code gives TLE (time limit error)
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string str, prefix, temp = ""; cin >> str >> prefix;
	int n = str.length(), m = prefix.length();
	vector <int> start_index;
	for (int i = 0; i < m; ++i)
		temp += str[i];
	if (temp == prefix)
		start_index.push_back(0);
	for (int i = m; i < n; ++i) {
		temp.erase(temp.begin());
		temp += str[i];
		if (temp == prefix)
			start_index.push_back((i + 1) - m);
	}
	cout << start_index.size() << endl;
}