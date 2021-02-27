#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (3));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    int ans=1e9+1;
    for(auto i : a) {
        if(i[0]<i[2]) {
            ans=min(ans, i[1]);
        }
    }
    if(ans==1e9+1) {
        ans=-1;
    }
    cout<<ans<<endl;
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

