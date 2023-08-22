#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, power = 0; cin >> t;
    while(t--) {
        int n; cin >> n;
        multiset<int> cards;
        while(n--) {
            int s; cin >> s;
            if(!s && !cards.empty()) {
                auto max = --cards.end();
                power += *max;
                cards.erase(max);
            }
            else if(s)
                cards.insert(s);
        }
        cout << power << endl;
        power = 0;
    }
    return 0;
}