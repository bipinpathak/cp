#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ap(ll n) {
    return (n*(n+1))/2;
}

ll sum(ll curr, ll count) {
    return ap(curr)-ap(curr-count);
}

ll calc(ll t, ll curr, ll use) {
    ll full=use%t;
    if(full==0) {
        full=t;
    }
    ll partial=t-full;
    ll high=(use+t-1)/t, low=high-1;
    ll ans=(partial*sum(curr, low))+(full*sum(curr, high));
    return ans;
}

void solve() {
    int n;
    ll k;
    cin>>n>>k;
    map<ll, ll> count;
    while(n--) {
        ll a;
        cin>>a;
        count[a]++;
    }
    vector<vector<ll>> options={{0, 0}};
    for(auto i : count) {
        options.push_back({i.first, i.second});
    }
    ll ans=0;
    while(k && (int)options.size()>1) {
        ll curr=options.back().front(), t=options.back().back();
        options.pop_back();
        options.back().back()+=t;
        ll prev=options.back().front();
        ll use=min(k, t*(curr-prev));
        ans+=calc(t, curr, use);
        k-=use;
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

