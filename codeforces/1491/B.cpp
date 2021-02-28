#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, u, v;
    cin>>n>>u>>v;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int ans=v+min(u, v);
    for(int i=1; i<n; i++) {
        if(abs(a[i]-a[i-1])>1) {
            ans=0;
            break;
        }
        if(a[i]!=a[i-1]) {
            ans=min(ans, u);
        }
        if(abs(a[i]-a[i-1])==1) {
            ans=min(ans, v);
        }
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

