#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int l, int r, int d, vector<int> &a, vector<int> &ans) {
    if(l>r) {
        return;
    }
    int index=l;
    for(int i=l; i<=r; i++) {
        if(a[i]>a[index]) {
            index=i;
        }
    }
    ans[index]=d;
    d++;
    go(l, index-1, d, a, ans);
    go(index+1, r, d, a, ans);
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), ans(n);
    for(auto &i : a) {
        cin>>i;
    }
    go(0, n-1, 0, a, ans);
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

