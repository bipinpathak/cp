#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i, s=0, m=0;
    string ans="HL";
    cin>>n;
    vector<int> a(n);
    for(int &i : a) cin>>i;
    for(int &i : a) {
        s+=i;
        m=max(m, i);
    }
    if(m>s/2 || s%2==1) ans="T";
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

