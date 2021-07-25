#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=998244353;

void solve() {
    ll n;
    cin>>n;
    vector<vector<ll>> a(n, vector<ll> (3));
    vector<ll> all;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
        all.push_back(i[0]);
        all.push_back(i[1]);
    }
    sort(all.begin(), all.end());
    map<ll, ll> index;
    int m=2*n;
    vector<ll> allone(m);
    for(ll i=0; i<m; i++) {
        index[all[i]]=i;
    }
    int done=0;
    ll last=0, total=0, ans=0;
    for(int i=0; i<m; i++) {
        ll curr=all[i];
        total=(total+curr-last)%mod;
        ans=(ans+curr-last)%mod;
        if(done<n && a[done][0]==curr) {
            ll prev=index[a[done][1]];
            ll cost=allone[prev];
            if(a[done][2]) {
                ans=(ans+total-cost)%mod;
            }
            total=(total*2)%mod;
            total=(total-cost)%mod;
            done++;
        }
        allone[i]=total;
        last=curr;
    }
    ans=(ans+1)%mod;
    if(ans<0) {
        ans+=mod;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

