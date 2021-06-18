#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string a, b;
    cin>>n>>a>>b;
    vector<set<int>> changes(20);
    int ans=0;
    for(int i=0; i<n && ans!=-1; i++) {
        if(a[i]==b[i]) {
            continue;
        }
        if(a[i]>b[i]) {
            ans=-1;
        } else {
            changes[a[i]-'a'].insert(b[i]-'a');
        }
    }
    for(int i=0; i<20 && ans!=-1; i++) {
        changes[i].erase(i);
        if(changes[i].empty()) {
            continue;
        }
        ans++;
        for(auto j : changes[i]) {
            changes[*changes[i].begin()].insert(j);
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

