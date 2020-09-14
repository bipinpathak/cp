#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i;
    cin>>n;
    vector<int> a(n), l(n), f;
    for(int &i : a) cin>>i;
    for(int &i : l) cin>>i;
    for(i=0; i<n; i++) {
        if(!l[i]) f.push_back(a[i]);
    }
    sort(f.begin(), f.end());
    for(i=0; i<n; i++) {
        if(!l[i]) {
            a[i]=f.back();
            f.pop_back();
        }
    }
    for(int &i : a) cout<<i<<" ";
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

