#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

void solve() {
    ll n, l, r;
    cin>>n>>l>>r;
    l+=3;
    r+=3;
    vector<ll> options(3), count(3);
    for(int i=0; i<3; i++) {
        options[i]=r/3-(l+2)/3+1;
        r--, l--;
    }
    count[0]=1;
    while(n--) {
        vector<ll> update(3); 
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                int curr=(i+j)%3;
                update[curr]=(update[curr]+(count[j]*options[i])%mod)%mod;
            }
        }
        count=update;
    }
    cout<<count[0]<<endl;
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

