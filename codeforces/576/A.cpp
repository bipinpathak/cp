#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int> ans, prime(n+1, 1);
    for(int i=2; i<=n; i++) {
        if(prime[i]) {
            for(int j=i*i; j<=n; j+=i) prime[j]=0;
        }
    }
    for(int i=2; i<=n; i++) {
        if(prime[i]) {
            ans.push_back(i);
            for(int j=i*i; j<=n; j*=i) ans.push_back(j);
        }
    }
    cout<<ans.size()<<endl;
    for(int i : ans) cout<<i<<" ";
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
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

