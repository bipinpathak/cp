#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll total=0, ans=0;
    for(auto &i : a) {
        cin>>i;
        total+=i;
    }
    total*=2;
    if(total%n==0) {
        total/=n;
        map<ll, ll> f;
        for(auto i : a) {
            ans+=f[total-i];
            f[i]++;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

