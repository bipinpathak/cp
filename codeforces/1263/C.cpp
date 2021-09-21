#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> ans;
    int x=1;
    while(x<=n) {
        int val=n/x;
        ans.push_back(val);
        x=n/val + 1;
    }
    ans.push_back(0);
    cout<<ans.size()<<endl;
    reverse(ans.begin(), ans.end());
    for(auto &i : ans) {
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

