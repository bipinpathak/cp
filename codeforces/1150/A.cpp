#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, r;
    cin>>n>>m>>r;
    vector<int> buy(n), sell(m);
    int goodBuy=1001, goodSell=0;
    for(auto &i : buy) {
        cin>>i;
        goodBuy=min(goodBuy, i);
    }
    for(auto &i : sell) {
        cin>>i;
        goodSell=max(goodSell, i);
    }
    int bought=r/goodBuy, ans;
    ans=r+max(0, bought*(goodSell-goodBuy));
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

