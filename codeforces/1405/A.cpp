#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i : a) cin>>i;
    reverse(a.begin(), a.end());
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

