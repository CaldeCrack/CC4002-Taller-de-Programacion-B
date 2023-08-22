#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> state;

int main(){
    int n, x, i = 0; cin >> n >> x;
    int half_x = x/2;
    priority_queue<state, vector<state>, greater<state>> menores, men_cpy;
    priority_queue<state> mayores;
    while(n--) {
        i++;
        int a; cin >> a;
        if(a >= x)
            continue;
        else if(a > half_x)
            mayores.push({a, i});
        else
            menores.push({a, i});
    }
    men_cpy = menores;
    while(!mayores.empty() && !menores.empty()) {
        int sum = mayores.top().first + menores.top().first;
        if(sum > x)
            mayores.pop();
        else if(sum < x)
            menores.pop();
        else {
            cout << mayores.top().second << " " << menores.top().second << endl;
            return 0;
        }
    }
    while(!men_cpy.empty()) {
        state aux;
        aux = men_cpy.top();
        men_cpy.pop();
        if(men_cpy.empty())
            break;
        if(aux.first + men_cpy.top().first == x) {
            cout << aux.second << " " << men_cpy.top().second << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}