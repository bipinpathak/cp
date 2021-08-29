#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=998244353;

ll calc(ll target, vector<ll> &ways) {
    ll ans=0;
    target=min(target, (ll)ways.size()-1);
    while(target>=0) {
        ans=(ans+ways[target])%mod;
        target--;
    }
    return ans;
}

void update(ll curr, vector<ll> &ways) {
    ll start=(int)ways.size()-1-curr;
    while(start>=0) {
        ways[start+curr]=(ways[start+curr]+ways[start])%mod;
        start--;
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int> (2));
    for(int i=0; i<n; i++) {
        cin>>a[i][0];
    }
    for(int i=0; i<n; i++) {
        cin>>a[i][1];
    }
    sort(a.begin(), a.end());
    int m=a.back().front();
    vector<ll> ways(m+1);
    ways[0]=1;
    ll ans=0;
    for(auto curr : a) {
        ll target=curr[0]-curr[1];
        ans=(ans+calc(target, ways))%mod;
        update(curr[1], ways);
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

