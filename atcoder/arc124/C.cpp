#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if(b==0) {
        return a;
    }
    return gcd(b, a%b);
}

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    set<vector<ll>> options={{0, 0}};
    for(auto i : a) {
        set<vector<ll>> update; 
        for(auto j : options) {
            vector<ll> add=j;
            add[0]=gcd(add[0], i[0]);
            add[1]=gcd(add[1], i[1]);
            sort(add.begin(), add.end());
            update.insert(add);
            add=j;
            reverse(add.begin(), add.end());
            add[0]=gcd(add[0], i[0]);
            add[1]=gcd(add[1], i[1]);
            sort(add.begin(), add.end());
            update.insert(add);
        }
        options=update;
    }
    ll ans=0;
    for(auto i : options) {
        ans=max(ans, (i[0]*i[1])/gcd(i[0], i[1]));
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
    auto start=clock();
    int t = 1;
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

