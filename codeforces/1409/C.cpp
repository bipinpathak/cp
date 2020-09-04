#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, x, y, i, d;
    cin>>n>>x>>y;
    d=n-1;
    while((y-x)%d) {
        d--;
    }
    d=(y-x)/d;
    vector<int>a(n, y);
    a[0]=y-(n-1)*d;
    while(a[0]<=0) {
        a[n-1]+=d;
        a[0]+=d;
    }
    for(i=n-2; i>=0; i--) {
        a[i]=a[i+1]-d;
    }
    for(i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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

