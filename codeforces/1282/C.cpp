#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll go(ll a, ll b, ll an, ll bn, ll t) {
    ll ans=0;
    if(t>0) {
        ll useEasy=min(an, t/a);
        ans+=useEasy;
        t-=a*useEasy;
        ll useHard=min(bn, t/b);
        ans+=useHard;
    }
    return ans;
}

void solve() {
    ll n, t, a, b;
    cin>>n>>t>>a>>b;
    vector<ll> hard(n);
    ll easy=0;
    for(auto &i : hard) {
        cin>>i;
        easy+=!i;
    }
    vector<vector<ll>> limit(n+1, vector<ll> (2));
    for(ll i=0; i<n; i++) {
        cin>>limit[i][0];
        limit[i][1]=i;
    }
    limit[n][0]=t+1;
    sort(limit.begin(), limit.end());
    ll easyNeeded=0, hardNeeded=0, ans=0;
    for(int i=0; i<=n; i++) {
        ll curr=limit[i][1], currTime=limit[i][0]-1;
        currTime-=easyNeeded*a+hardNeeded*b;
        if(currTime>=0) {
            ll easyLeft=easy-easyNeeded, hardLeft=(n-easy)-hardNeeded;
            ll extra=go(a, b, easyLeft, hardLeft, currTime);
            ans=max(ans, easyNeeded+hardNeeded+extra);
        }
        easyNeeded+=!hard[curr];
        hardNeeded+=hard[curr];
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

