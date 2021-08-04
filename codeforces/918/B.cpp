#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    map<string, string> name;
    while(n--) {
        string a, b;
        cin>>a>>b;
        name[b]=a;
    }
    vector<vector<string>> ans;
    while(m--) {
        string a, b;
        cin>>a>>b;
        ans.push_back({});
        ans.back().push_back(a);
        ans.back().push_back(" ");
        ans.back().push_back(b);
        ans.back().push_back(" #");
        b.pop_back();
        ans.back().push_back(name[b]);
    }
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j;
        }
        cout<<endl;
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

