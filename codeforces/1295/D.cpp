#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int coef(ll a) {
    map<ll, ll> count;
    for(ll i=2; i*i<=a; i++) {
        while(a%i==0) {
            count[i]++;
            a/=i;
        }
    }
    if(a>1) {
        count[a]++;
    }
    int ans=1;
    for(auto i : count) {
        ans*=-1;
        if(i.second>1) {
            ans=0;
            break;
        }
    }
    return ans;
}

ll val(ll low, ll high, ll p) {
    ll ans=high/p - (low-1)/p;
    return ans;
}

void solve() {
    ll a, m;
    cin>>a>>m;
    ll g=__gcd(a, m);
    a/=g;
    m/=g;
    ll ans=0;
    for(ll i=1; i*i<=m; i++) {
        if(m%i==0) {
            ans+=coef(i)*val(a, a+m-1, i); 
            if(i*i!=m) {
                ans+=coef(m/i)*val(a, a+m-1, m/i); 
            }
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

