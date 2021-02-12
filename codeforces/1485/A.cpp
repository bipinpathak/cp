#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int go(int a, int b) {
    int ans=0;
    while(a) {
        a/=b;
        ans++;
    }
    return ans;
}

void solve() {
    int a, b;
    cin>>a>>b;
    int ans=1e9, cost=0;
    if(b==1) {
        b++;
        cost++;
    }
    while(1) {
        int offer=go(a, b)+cost;
        if(offer>ans) {
            break;
        }
        ans=offer;
        b++;
        cost++;
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

