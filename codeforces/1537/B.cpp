#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dist(vector<ll> a, vector<ll> b) {
    return abs(a[0]-b[0])+abs(a[1]-b[1]);
}

void solve() {
    ll n, m, x, y;
    cin>>n>>m>>x>>y;
    vector<ll> start={x, y};
    vector<vector<ll>> options={{1, 1}, {1, m}, {n, 1}, {n, m}};
    vector<vector<ll>> ans(2);
    ll best=0;
    for(ll i=0; i<4; i++) {
        for(ll j=0; j<4; j++) {
            ll offer=min(dist(start, options[i])+dist(options[i], options[j])+dist(options[j], start), dist(start, options[j])+dist(options[j], options[i])+dist(options[i], start));
            if(offer>=best) {
                best=offer;
                ans={options[i], options[j]};
            }
        }   
    }
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
        }
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

