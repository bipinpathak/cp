#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i;
    cin>>n;
    vector<long long> a(n);
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    long long ans=0, p=1e9+7;
    vector<long long> powers(n,1);
    for(i=1; i<n; i++) {
        powers[i]=(powers[i-1]*2)%p;
    }
    for(i=0; i<n; i++) {
        ans=(ans+(powers[i]*(a[i]-a[n-1-i])%p)%p)%p;
        ans=(ans+p)%p;
    }
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
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

