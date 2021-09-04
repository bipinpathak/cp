#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int L, q;
    cin>>L>>q;
    set<vector<int>> active={{L, 0}};
    while(q--) {
        int c, x;
        cin>>c>>x;
        if(c==1) {
            auto i=*active.lower_bound({x, 0});
            active.erase(i);
            int l=i[1], r=i[0];
            vector<int> left={l, x}, right={x, r};
            reverse(left.begin(), left.end());
            reverse(right.begin(), right.end());
            active.insert(left);
            active.insert(right);
        } else {
            auto i=*active.lower_bound({x, 0});
            cout<<i[0]-i[1]<<endl;
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

