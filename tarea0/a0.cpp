// https://vjudge.net/contest/573906#problem/A
#include <iostream>
using namespace std;

int w;

int main(){
    cin >> w;
    if (w%2==0 && w!=2){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}