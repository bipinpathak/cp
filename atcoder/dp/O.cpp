#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p=1e9+7;
int n;
vector<ll> dp;

ll fetch(int index, int used, vector<vector<int>> &a) {
    if(index==n) {
        return 1;
    } else if(dp[used]==-1) {
        ll build=0;
        for(int i=0; i<n; i++) {
            if(a[index][i]==0 || (used&(1<<i))) {
                continue;
            }
            build=(build+fetch(index+1, used+(1<<i), a))%p;
        }
        dp[used]=build;
    }
    return dp[used];
}

void solve() {
    cin>>n;
    vector<vector<int>> a(n, vector<int> (n));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    dp.resize((1<<n)-1, -1);
    cout<<fetch(0, 0, a)<<endl;
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

