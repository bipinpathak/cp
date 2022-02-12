#include "bits/stdc++.h"
using namespace std;
using ll = long long;

map<int, int> f;

bool custom(int a, int b) {
    if(f[a]>f[b]) {
        return true;
    } else if(f[a]==f[b]) {
        return a>b;
    }
    return false;
}

void solve() {
    f.clear();
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
        f[i]++;
    }
    vector<vector<int>> values(n+1);
    for(auto &[i, fi]: f) {
        values[fi].push_back(i);
    }
    vector<vector<int>> small;
    for(auto &i : values) {
        reverse(i.begin(), i.end());
        small.push_back(i);
    }
    map<int, set<int>> bad;
    while(m--) {
        int x, y;
        cin>>x>>y;
        bad[x].insert(y);
        bad[y].insert(x);
    }
    m=(int)small.size();
    ll ans=0;
    for(int i=1; i<m; i++) {
        for(auto &val :  small[i]) {
            for(int j=i; j>=0; j--) {
               for(int k=0; k<(int)small[j].size(); k++) {
                   if(small[j][k]==val) {
                        continue;
                   }
                   if(!bad[val].count(small[j][k])) {
                        ans=max(ans, (ll)(f[val]+f[small[j][k]])*(val+small[j][k]));
                        break;
                   }
               }
            }
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

