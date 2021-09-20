#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    vector<int> c(n);
    for(int i=0; i<n; i++) {
        cin>>c[i];
        a[i].resize(c[i]);
        for(auto &j : a[i]) {
            cin>>j;
        }
    }
    int m;
    cin>>m;
    vector<int> build(n);
    set<vector<int>> banned;
    while(m--) {
        for(auto &j : build) {
            cin>>j;
            j--;
        }
        banned.insert(build);
    }
    pair<int, vector<int>> curr;
    set<pair<int, vector<int>>> active;
    for(int i=0; i<n; i++) {
        curr.first-=a[i].back();
        curr.second.push_back(c[i]-1);
    }
    active.insert(curr);
    while(1) {
        curr=*active.begin();
        active.erase(active.begin());
        if(!banned.count(curr.second)) {
            for(auto i : curr.second) {
                cout<<i+1<<" ";
            }
            cout<<endl;
            return;
        }
        for(int i=0; i<n; i++) {
            if(curr.second[i]) {
                curr.first+=a[i][curr.second[i]];
                curr.second[i]--;
                curr.first-=a[i][curr.second[i]];
                active.insert(curr);
                curr.first+=a[i][curr.second[i]];
                curr.second[i]++;
                curr.first-=a[i][curr.second[i]];
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

