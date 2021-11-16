#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int u, h;
    cin>>u>>h;
    vector<vector<int>> stone(2, vector<int> (2));
    for(auto &i : stone) {
        for(auto &j : i) {
            cin>>j;
        }
        reverse(i.begin(), i.end());
    }
    sort(stone.begin(), stone.end());
    while(h) {
        u+=h;
        if(!stone.empty() && stone.back().front()==h) {
            u-=stone.back().back();
            stone.pop_back();
            u=max(u, 0);
        }
        h--;
    }
    cout<<u<<endl;
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

