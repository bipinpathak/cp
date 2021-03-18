#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> ans(n);
    for(int i=n-1; i>=n/2; i--) {
        cin>>ans[i];
    }
    for(int i=n-2; i>=n/2; i--) {
        ll last=ans[i+1]+ans[n-2-i];
        if(last<=ans[i]) {
            ans[n-1-i]=ans[i]-ans[i+1];
            ans[i]=ans[i+1];
        } else {
            ans[n-1-i]=ans[n-2-i];
            ans[i]-=ans[n-1-i];
        }
    }
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

