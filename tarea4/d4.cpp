// https://vjudge.net/contest/589666#problem/D
#include <bits/stdc++.h>
using namespace std;

template <class T, T merge(T,T)>
struct segment_tree{
    int N;
    vector <T> tree;
    segment_tree(int _N){
        N = _N;
        tree.resize(4*N);
        build(0, 0, N-1);
    }

    segment_tree(vector <T> &A){
        N = int(A.size());
        tree.resize(4*N);
        build(0, 0, N-1, A);
    }

    void build(int n, int i, int j){
        if(i == j){
        tree[n] = T(); // initial value
        return;
        }
        int mid = (i+j)/2;
        build(2*n+1, i, mid);
        build(2*n+2, mid+1, j);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }

    void build(int n, int i, int j, vector <T> &A){
        if(i == j){
        tree[n] = A[i]; // initial value
        return;
        }
        int mid = (i+j)/2;
        build(2*n+1, i, mid, A);
        build(2*n+2, mid+1, j, A);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }

    T query(int l, int r){
        return query(0, 0, N-1, l, r);
    }

    T query(int n, int i, int j, int l, int r){
        if(l <= i && j <= r) return tree[n];
        int mid = (i+j)/2;
        if(mid < l || r < i)
        return query(2*n+2, mid+1, j, l, r);
        if(j < l || r < mid+1)
        return query(2*n+1, i, mid, l, r);
        return merge(
            query(2*n+1, i, mid, l, r),
            query(2*n+2, mid+1, j, l, r));
    }

    void update(int t, T val){
        update(0, 0, N-1, t, val);
    }

    void update(int n, int i, int j, int t, T val){
        if(t < i || j < t) return;
        if(i == j){
        tree[n] = val;
        return;
        }
        int mid = (i+j)/2;
        update(2*n+1, i, mid, t, val);
        update(2*n+2, mid+1, j, t, val);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }
};

int merge(int a, int b){
    return max(a, b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s; int q; cin >> s >> q;
    int n = s.length();
    // initialization of segment trees
    vector <segment_tree <int, merge>> oc;
    for(int i = 0; i < 26; i++) {
        vector <int> v(n, 0);
        segment_tree <int, merge> st(v);
        oc.push_back(st);
    }
    // update based on the string
    for(int i = 0; i < n; i++) {
        char c = s[i];
        oc[c - 'a'].update(i, 1);
    }
    // resolve queries
    for(int k = 0; k < q; k++) {
        int j; cin >> j;
        if(j == 1) {
            int i; char c; cin >> i >> c;
            char s_char = s[--i];
            oc[s_char - 'a'].update(i, 0);
            oc[c - 'a'].update(i, 1);
            s[i] = c;
        } else {
            int res = 0, l, r; cin >> l >> r;
            l--; r--;
            for(int i = 0; i < 26; i++)
                res += oc[i].query(l, r);
            cout << res << endl;
        }
    }
    return 0;
}