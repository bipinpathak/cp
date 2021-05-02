#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, x;
    cin>>n>>m>>x;
    vector<vector<int>> h(n, vector<int> (2));
    set<vector<int>> active;
    for(int i=0; i<n; i++) {
        cin>>h[i][0];
        h[i][1]=i;
        if(i<m) {
            active.insert({0, i+1});
        }
    }
    sort(h.rbegin(), h.rend());
    vector<int> ans(n);
    for(auto i : h) {
        auto curr=*active.begin();
        active.erase(active.begin());
        curr[0]+=i[0];
        ans[i[1]]=curr[1];
        active.insert(curr);
    }
    if(active.rbegin()->front()-active.begin()->front()>x) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(auto i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

