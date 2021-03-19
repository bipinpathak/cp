#include <bits/stdc++.h>
using namespace std;
using ll = int;

ll high=2e7;
vector<ll> seive(high+1, 1);

ll go(ll c, ll d, ll x, ll g) {
    ll ans=1, product=(x/g + d)/c;
    while(product>1) {
        ll curr=seive[product];
        ans*=2;
        while(product%curr==0) {
            product/=curr;
        }
    }
    return ans;
}

void solve() {
    ll c, d, x;
    cin>>c>>d>>x;
    vector<ll> g;
    for(ll i=1; i*i<=x; i++) {
        if(x%i==0) {
            g.push_back(i);
            if(i!=x/i) {
                g.push_back(x/i);
            }
        }
    }
    ll ans=0;
    for(auto i : g) {
        if((x/i + d)%c==0) {
            ans+=go(c, d, x, i);
        }
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
    for(long long i=2; i<=high; i++) {
        if(seive[i]!=1) {
            continue;
        }
        for(long long j=i; j<=high; j+=i) {
            seive[j]=i;
        }
    }
    while(t--) {
        solve();
    }
    return 0;
}