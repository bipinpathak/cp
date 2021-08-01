#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> out(n);
    while(m--) {
        int u, v;
        cin>>u>>v;
        u--, v--;
        out[min(u, v)]++;
    }
    set<int> zero;
    for(int i=0; i<n; i++) {
        if(out[i]==0) {
            zero.insert(i);
        }
    }
    int q;
    cin>>q;
    while(q--) {
        int t;
        cin>>t;
        if(t==3) {
            cout<<zero.size()<<endl;
            continue;
        }
        int u, v;
        cin>>u>>v;
        u--, v--;
        if(u>v) {
            swap(u, v);
        }
        if(t==1) {
            if(out[u]==0) {
                zero.erase(u);
            }
            out[u]++;
        } else {
            out[u]--;
            if(out[u]==0) {
                zero.insert(u);
            }
        }
    }
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
