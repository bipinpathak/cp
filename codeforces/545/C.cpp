#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i, ans;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (2));
    for(i=0; i<n; i++) {
        cin>>a[i][0]>>a[i][1];
    }
    ans=min(2, n);
    for(i=1; i<n-1; i++) {
        if(a[i-1][0]<a[i][0]-a[i][1]) ans+=1;
        else if(a[i][0]+a[i][1]<a[i+1][0]) {
            ans+=1;
            a[i][0]+=a[i][1];
        }
        a[i][0]=max(a[i][0], a[i-1][0]);
    }
    cout<<ans<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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

