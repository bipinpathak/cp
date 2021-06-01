#include <bits/stdc++.h>
using namespace std;
using ll = long long;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(mt);
}

void solve() {
    int n, m, p;
    cin>>n>>m>>p;
    vector<string> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    vector<int> ans;
    int trials=50;
    while(trials--) {
        int index=rand(0, n-1);
        vector<int> on;
        for(int i=0; i<m; i++) {
            if(a[index][i]=='1') {
                on.push_back(i);
            }
        }
        p=(int)on.size();
        vector<int> dp((1<<p), 0);
        for(int i=0; i<n; i++) {
            int mask=0;
            for(int j=0; j<p; j++) {
                if(a[i][on[j]]=='1') {
                    mask^=(1<<j);
                }
            }
            dp[mask]++;
        }
        for(int i=0; i<p; i++) {
            for(int mask=(1<<p)-1; mask>=0; mask--) {
                if(mask&(1<<i)) {
                    continue;
                }
                dp[mask]+=dp[mask+(1<<i)];
            }
        }
        for(int mask=0; mask<(1<<p); mask++) {
            if(dp[mask]<(n+1)/2) {
                continue;
            }
            if(__builtin_popcount(mask)<=ans.size()) {
                continue;
            }
            ans.clear();
            for(int i=0; i<p; i++) {
                if(mask&(1<<i)) {
                    ans.push_back(on[i]);
                }
            }
        }
    }
    string s(m, '0');
    for(auto i : ans) {
        s[i]='1';
    }
    cout<<s<<endl;
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

