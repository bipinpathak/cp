#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int calc(ll a) {
    int ans=0;
    while(a) {
        ans+=a&1;
        a>>=1;
    }
    return ans;
}   

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        ll x;
        cin>>x;
        i=calc(x);
    }
    n=64;
    vector<vector<vector<int>>> store(n, vector<vector<int>> (2));
    ll ans=0;
    int total=0;
    for(auto x : a) {
        for(int i=x-1; i>=0; i--) {
            for(int j=0; j<2; j++) {
                for(auto k : store[i][j]) {
                    store[x][j].push_back(k);
                }
                store[i][j].clear();
            }
        }
        store[x][total&1].push_back(total);
        total+=x;
        int p=total&1;
        for(int i=x; i<n; i++) {
            int need=total-2*i; 
            ans+=upper_bound(store[i][p].begin(), store[i][p].end(), need)-upper_bound(store[i][p].begin(), store[i][p].end(), -1);
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

