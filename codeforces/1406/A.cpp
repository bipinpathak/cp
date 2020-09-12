#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, ans=0, count=0, i;
    cin>>n;
    vector<int> f(101, 0);
    while(n--) {
        cin>>i;
        f[i]++;
    }
    i=0;
    while(f[i]) {
        f[i]--;
        i++;
    }
    ans+=i;
    i=0;
    while(f[i]) {
        f[i]--;
        i++;
    }
    ans+=i;
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

