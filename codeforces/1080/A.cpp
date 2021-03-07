#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k, ans;
    cin>>n>>k;
    ans=(2*n+k-1)/k+(5*n+k-1)/k+(8*n+k-1)/k;
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
    while(t--) {
        solve();
    }
    return 0;
}

