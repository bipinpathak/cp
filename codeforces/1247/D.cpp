#include "bits/stdc++.h"
using namespace std;
using ll = long long;

vector<int> lp;

void pre() {
    int n=1e5;
    lp.resize(n+1, 0);
    vector<int> primes;
    for(int i=2; i<=n; i++) {
        if(lp[i]==0) {
            primes.push_back(i);
            lp[i]=i;
        }
        for(auto j : primes) {
            if(j>lp[i] || j*i>n) {
                break;
            }
            lp[i*j]=j;
        }
    }
    return;
}

void solve() {
    int n, k;
    cin>>n>>k;
    map<vector<vector<int>>, int> count;
    ll ans=0;
    while(n--) {
        int a;
        cin>>a;
        map<int, int> active;
        while(lp[a]) {
            active[lp[a]]++;
            a/=lp[a];
        }
        vector<vector<int>> all;
        for(auto &[p, f] : active) {
            f%=k;
            if(f) {
                all.push_back({p, k-f});
            }
        }
        ans+=count[all];
        for(auto &i : all) {
            i[1]=k-i[1];
        }
        count[all]++;
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
    pre();
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

