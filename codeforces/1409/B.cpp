#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long a, b, x, y, n, fa, fb, temp, ans;
    cin>>a>>b>>x>>y>>n;
    fa=a-min(n, a-x);
    fb=b-min(b-y, n-a+fa);
    ans=fa*fb;
    fb=b-min(b-y, n);
    fa=a-min(a-x, n-b+fb);
    ans=min(ans, fa*fb);
    cout<<ans<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

