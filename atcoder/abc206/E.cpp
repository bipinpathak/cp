#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll l, r;
    cin>>l>>r;
    vector<ll> lp(r+1), p;
    for(ll i=2; i<=r; i++) {
        if(lp[i]==0) {
            p.push_back(i);
            lp[i]=i;
        }
        for(auto j : p) {
            if(j>lp[i] || i*j>r) {
                break;
            }
            lp[i*j]=j;
        }
    }
    l=max(l, (ll)2);
    ll coprime=0, products=0, n=r-l+1, ans;
    for(int i=1; i<=r; i++) {
        ll multiples=r/i - (l+i-1)/i + 1; 
        ll pairs=multiples*multiples;
        if(i>=l) {
            products+=2*multiples-1;
        }
        set<ll> seen;
        ll curr=i;
        while(curr>1) {
            if(seen.count(lp[curr])) {
                pairs=0;
                break;
            }
            seen.insert(lp[curr]);
            curr/=lp[curr];
            pairs*=-1;
        }
        coprime+=pairs;
    }   
    ans=n*n-coprime-products;
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

