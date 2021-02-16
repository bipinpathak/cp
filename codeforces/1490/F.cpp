#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    map<int, int> f;
    for(auto &i : a) {
        cin>>i;
        f[i]++;
    }
    vector<int> b;
    for(auto i : f) {
        b.push_back(i.second);
    }
    sort(b.rbegin(), b.rend());
    int ans=n;
    for(int i=0; i<(int) b.size(); i++) {
        ans=min(ans, n-(i+1)*b[i]);
    }
    cout<<ans<<endl;
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

