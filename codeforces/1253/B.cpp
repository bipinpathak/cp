#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    set<int> active, seen;
    vector<vector<int>> ans={{}};
    for(auto i : a) {
        ans.back().push_back(i);
        if(i<0) {
            i*=-1;
            if(!active.count(i)) {
                cout<<-1<<endl;
                return;
            }
            active.erase(i);
        } else {
            if(active.count(i) || seen.count(i)) {
                cout<<-1<<endl;
                return;
            }
            active.insert(i);
            seen.insert(i);
        }
        if(active.empty()) {
            seen.clear();
            ans.push_back({});
        }
    }
    if(!active.empty()) {
        cout<<-1<<endl;
        return;
    }
    ans.pop_back();
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        cout<<i.size()<<" ";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

