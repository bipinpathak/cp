#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long x, y, k, ans;
    cin>>x>>y>>k;
    ans=k*(y+1)+x-3;
    ans/=(x-1);
    ans+=k;
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

