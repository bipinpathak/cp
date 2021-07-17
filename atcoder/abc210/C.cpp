#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> c(n);
    for(auto &i : c) {
        cin>>i;
    }
    map<int, int> f;
    int ans=0;
    for(int i=0; i<n; i++) {
        f[c[i]]++;
        if(i-k>=0) {
            f[c[i-k]]--;
            if(f[c[i-k]]==0) {
                f.erase(c[i-k]);
            }
        }
        ans=max(ans, (int)f.size());
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

