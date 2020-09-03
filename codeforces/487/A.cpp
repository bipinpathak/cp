#include <bits/stdc++.h>
using namespace std;
void solve() {
    int i, j, k, h, a, d, tm, ans=-1;
    vector<int> y(3), m(3);
    for(i=0; i<3; i++) cin>>y[i];
    for(i=0; i<3; i++) cin>>m[i];
    cin>>h>>a>>d;
    for(j=max(y[1], m[2]+1); j<=200; j++) {
        for(k=y[2]; k<=100; k++) {
            if(ans==-1) ans=INT_MAX;
            tm=(m[0]+j-m[2]-1)/(j-m[2]);
            i=1+max(0,m[1]-k)*tm;
            ans=min(ans, max(h*(i-y[0]), 0)+a*(j-y[1])+d*(k-y[2]));
        }
    }
    ans=max(ans, 0);
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

