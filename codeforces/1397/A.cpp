#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i;
    cin>>n;
    vector<string> a(n);
    for(i=0; i<n; i++) {
        cin>>a[i];
    }
    vector<int> f(26,0);
    for(i=0; i<n; i++) {
        for(char c : a[i]) {
            f[c-'a']++;
        }
    }
    for(int i : f) {
        if(i%n) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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
