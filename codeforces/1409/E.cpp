#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k, i, j, ans=0, temp=0;
    cin>>n>>k;
    vector<int> x(n), y(n), start(n), optimal(n);
    for(i=0; i<n; i++) cin>>x[i];
    for(i=0; i<n; i++) cin>>y[i];
    sort(x.begin(), x.end());
    j=n-1;
    for(i=n-1; i>=0; i--) {
        while(x[j]-x[i]>k) j--;
        start[i]=j-i+1;
        optimal[i]=max(start[i], temp);
        temp=optimal[i];
    }
    for(i=0; i<n; i++) {
        ans=max(ans, start[i]+(i+start[i]<n?optimal[i+start[i]]:0));
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

