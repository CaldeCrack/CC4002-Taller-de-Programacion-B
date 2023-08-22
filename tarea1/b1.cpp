#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, power = 0; cin >> t;
    while(t--) {
        int n; cin >> n;
        stack<int> cards;
        while(n--) {
            int s; cin >> s;
            if(!s && !cards.empty()) {
                power += cards.top();
                cards.pop();
            }
            else if(s && (cards.empty() || cards.top() <= s)) {
                cards.push(s);
            }
        }
        cout << power << endl;
        power = 0;
    }
    return 0;
}