#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    map<int, vector<int>> row;
    while(m--) {
        int x, y;
        cin>>x>>y;
        row[x].push_back(y);
    }
    set<int> active;
    active.insert(n);
    for(auto i : row) {
        stack<int> add, remove;
        for(auto j : i.second) {
            if(active.count(j)!=0 && active.count(j-1)==0 && active.count(j+1)==0) {
                remove.push(j);
            }
            if(active.count(j)==0 && (active.count(j-1) || active.count(j+1))) {
                add.push(j);
            }
        }
        while(!add.empty()) {
            active.insert(add.top());
            add.pop();
        }
        while(!remove.empty()) {
            active.erase(remove.top());
            remove.pop();
        }
    }
    cout<<active.size()<<endl;
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

