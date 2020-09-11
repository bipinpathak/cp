#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin>>s;
    int n=s.length(), i, j, ans=0;
    vector<int> a(n, 0), b(n, 0);
    for(i=0; i<n; i++) {
        if(s[i]=='a') a[i]++;
        else b[i]++;
    }
    for(i=1; i<n; i++) {
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    ans=max(a[n-1], b[n-1]);
    for(i=0; i<n; i++) {
        for(j=i; j<n; j++) {
            int offer;
            offer=a[n-1]+b[j]-a[j]-(i?(b[i-1]-a[i-1]):0);
            ans=max(ans, offer);
        }
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

