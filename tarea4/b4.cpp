// https://vjudge.net/contest/589666#problem/B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
    int N;
    vector <ll> tree;
    const ll neutro = 1e18;

    SegmentTree(vector <ll> &A) {
        N = A.size();
        tree.resize(4*N);
        build(0, 0, N-1, A);
    }

    ll merge(ll a, ll b) {
        return min(a, b);
    }

    void build(int n, int i, int j, vector <ll> &A) {
        if(i == j) {
            tree[n] = A[i];
            return;
        }
        int mid = (i+j)/2;
        build(2*n+1, i, mid, A);
        build(2*n+2, mid+1, j, A);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }

    ll query(int l, int r) {
        return query(0, 0, N-1, l, r);
    }

    ll query(int n, int i, int j, int l, int r) {
        if(l <= i && j <= r)
            return tree[n];
        if (r < i || j < l)
            return neutro;
        int mid = (i+j)/2;
        return merge(query(2*n+1, i, mid, l, r), query(2*n+2, mid+1, j, l, r));
    }

    void update(int k, ll val) {
        update(0, 0, N-1, k, val);
    }

    void update(int n, int i, int j, int k, ll val) {
        if(k < i || k > j)
            return;
        if(i == j) {
            tree[n] = val;
            return;
        }
        int mid = (i+j)/2;
        update(2*n+1, i, mid, k, val);
        update(2*n+2, mid+1, j, k, val);
        tree[n] = merge(tree[2*n+1], tree[2*n+2]);
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector <ll> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    SegmentTree ST(arr);
    while(q--) {
        int option, a, b; cin >> option >> a >> b;
        a--;
        if(option == 1)
            ST.update(a, b);
        else
            cout << ST.query(a, --b) << endl;
    }
    return 0;
}