#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    int high=0;
    for(auto &i : a) {
        cin>>i;
        high=max(high, i);
    }
    int ans=(x+high-1)/high;
    if(ans==1) {
        ans++;
        for(auto &i : a) {
            if(i==x) {
                ans=1;
                break;
            }
        }
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

