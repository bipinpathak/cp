#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int m=512;
    vector<int> seen(m, m);
    for(auto i : a) {
        seen[i]=min(seen[i], i);
        for(int target=0; target<m; target++) {
            int need=i^target;
            if(seen[need]<i) {
                seen[target]=min(seen[target], i);
            }
        }
    }
    vector<int> ans;
    seen[0]=0;
    for(int i=0; i<m; i++) {
        if(seen[i]<m) {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

