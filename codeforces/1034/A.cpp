#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}
void solve() {
    int n, i, j, ans=0, x=0, m=1+15*1e6;
    cin>>n;
    vector<int> a(n), f(m), c(m);
    for(auto &i : a) cin>>i;
    for(i=0; i<n; i++) x=gcd(a[i], x);
    for(i=2; i<m; i++) {
        if(f[i]) continue;
        for(j=i; j<m; j+=i) f[j]=i;
    }
    for(auto &i : a) {
        i/=x;
        while(i>1) {
            int p=f[i];
            while(i%p==0) i/=p;
            ans=max(ans, ++c[p]);
        }
    }
    ans=n-ans;
    if(ans==n) ans=-1;
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

