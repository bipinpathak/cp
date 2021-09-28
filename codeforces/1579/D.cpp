#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    priority_queue<vector<int>> active;
    for(int i=1; i<=n; i++) {
        int a;
        cin>>a;
        if(a) {
            active.push({a, i});
        }
    }
    vector<vector<int>> ans;
    while((int)active.size()>1) {
        auto left=active.top();
        active.pop();
        auto right=active.top();
        active.pop();
        ans.push_back({left[1], right[1]});
        left[0]--, right[0]--;
        if(left[0]) {
            active.push(left);
        }
        if(right[0]) {
            active.push(right);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i : ans) {
        for(auto j : i) {
            cout<<j<<" ";
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

