#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, w;
    cin>>n>>w;
    ll total=0;
    vector<vector<ll>> items(n, vector<ll> (2));
    for(auto &i : items) {
        cin>>i[0]>>i[1];
        total+=i[1];
    }
    vector<ll> weight(total+1, w+1);
    weight[0]=0;
    for(auto item : items) {
        ll wi=item[0], vi=item[1];
        for(ll curr=total-vi; curr>=0; curr--) {
            weight[curr+vi]=min(weight[curr+vi], weight[curr]+wi);
        }
    }
    for(ll i=total; i>=0; i--) {
        if(weight[i]<=w) {
            cout<<i<<endl;
            return;
        }
    }
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
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}
