#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m, i;
    cin>>n>>m;
    vector<int> ans(n, 0);
    vector<pair<int, int>> increasing, decreasing;
    for(i=0; i<m; i++) {
        int t, l, r;
        cin>>t>>l>>r;
        l--;
        r--;
        if(t) increasing.push_back(make_pair(l, r));
        else decreasing.push_back(make_pair(l, r));
    }
    sort(increasing.begin(), increasing.end());
    for(i=0; i<n; i++) ans[i]=n-i;
    for(auto check : increasing) {
        int start=check.first, end=check.second;
        for(i=start+1; i<=end; i++) ans[i]=ans[start];
    }
    for(auto check : decreasing) {
        bool good=false;
        int start=check.first, end=check.second;
        while(!good && start<end) {
            if(ans[start]>ans[start+1]) {
                good=true;
            }
            start++;
        }
        if(!good) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
    for(int i : ans) cout<<i<<" ";
    cout<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

