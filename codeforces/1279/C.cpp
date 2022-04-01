#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> gifts(n), order(m);
    for(auto &i : gifts) {
        cin>>i;
        i--;
    }
    for(auto &i : order) {
        cin>>i;
        i--;
    }
    vector<int> index(n);
    for(int i=0; i<n; i++) {
        index[gifts[i]]=i;
    }
    int done=-1;
    ll ans=0;
    for(int i=0; i<m; i++) {
        if(index[order[i]]>done) {
            ans+=2*(index[order[i]]-i);
        }
        ans++;
        done=max(done, index[order[i]]);
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

