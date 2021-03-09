#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, d;
    cin>>n>>d;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    for(int i=1; i<n; i++) {
        int possible=min(a[i], d/i);
        a[0]+=possible;
        d-=possible*i;
    }
    cout<<a[0]<<endl;
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

