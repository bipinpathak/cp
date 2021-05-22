#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(auto &i : a) {
        cin>>i;
    }
    for(auto &i : b) {
        cin>>i;
    }
    for(auto &i : c) {
        cin>>i;
    }
    map<int, int> count;
    for(auto i : c) {
        count[b[i-1]]++;
    }
    ll ans=0;
    for(auto i : a) {
        ans+=count[i];
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

