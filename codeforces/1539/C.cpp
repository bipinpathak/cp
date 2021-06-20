#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, k, x;
    cin>>n>>k>>x;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    ll last=a[0];
    vector<ll> left;
    for(auto i : a) {
        ll diff=i-last;
        if(diff>x) {
            left.push_back(diff);
        }           
        last=i;
    }
    ll ans=(int)left.size()+1;
    for(auto &i : left) {
        i=(i+x-1)/x -1;
    }
    sort(left.begin(), left.end());
    for(auto i : left) {
        if(i<=k) {
            k-=i;
            ans--;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

