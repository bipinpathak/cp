#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i, ans=0;
    cin>>n;
    vector<int> a(n);
    for(int &i : a) cin>>i;
    vector<int> increasing(n, 1), decreasing(n, 1);
    for(i=1; i<n; i++) if(a[i]>=a[i-1]) increasing[i]+=increasing[i-1];
    for(i=n-2; i>=0; i--) if(a[i]>=a[i+1]) decreasing[i]+=decreasing[i+1];
    for(i=0; i<n; i++) ans=max(ans, increasing[i]+decreasing[i]-1);
    cout<<ans<<endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

