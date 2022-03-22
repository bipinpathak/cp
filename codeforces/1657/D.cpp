#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, totalCoins;
    cin>>n>>totalCoins;
    vector<ll> pick(totalCoins+1), best(totalCoins+1);
    vector<vector<int>> update(totalCoins+1);
    map<ll, int> active;
    while(n--) {
        int c, d, h;
        cin>>c>>d>>h;
        pick[c]=max(pick[c], (ll)d*h);
    }
    for(int i=1; i<=totalCoins; i++) {
        if(pick[i]) {
            for(int j=1; j<=totalCoins/i; j++) {
                best[j*i]=max(best[j*i], pick[i]*j);
            }
        }
        best[i]=max(best[i], best[i-1]);
    }
    int m;
    cin>>m;
    vector<ll> monsters(m);
    for(auto &i : monsters) {
        ll d, h;
        cin>>d>>h;
        i=d*h;
    }
    for(int i=0; i<m; i++) {
        ll ans=-1;
        if(monsters[i]<best.back()) {
            ans=upper_bound(best.begin(), best.end(), monsters[i])-best.begin();
        }
        cout<<ans<<" ";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

