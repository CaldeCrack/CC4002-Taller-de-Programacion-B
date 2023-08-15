#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int last = 96;
    for(int i=0; i<s.size(); i++){
        if(s[i] > last){
            if(s[i] - last == 1) last = s[i];
            else {
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    return 0;
}