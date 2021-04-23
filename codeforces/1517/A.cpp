#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sum(ll n) {
    ll ans=0;
    while(n) {
        ans+=n%10;
        n/=10;
    }
    return ans;
}

void solve() {
    ll n;
    cin>>n;
    if(n%2050) {
        cout<<-1<<endl;
        return;
    }
    n/=2050;
    cout<<sum(n)<<endl;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

