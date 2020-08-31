#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i, ans=0;
    cin>>n;
    vector<int> a(n), left(n, 1), right(n, 1);
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    for(i=1; i<n; i++) {
        if(a[i-1]<a[i]) {
            left[i]+=left[i-1];
        }
        if(a[n-1-i]<a[n-i]) {
            right[n-i-1]+=right[n-i];
        }
    }
    for(i=0; i<n; i++) {
        //cout<<left[i]<<" "<<right[i]<<endl;
        ans=max(ans, max(left[i], right[i]));
        if(i-1>=0 && i+1<n && a[i-1]<a[i+1]) {
            ans=max(ans, left[i-1]+right[i+1]);
        }
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
