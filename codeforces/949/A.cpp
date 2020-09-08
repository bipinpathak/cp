#include <bits/stdc++.h>
using namespace std;
void solve() {
    int i, n;
    string s;
    cin>>s;
    n=s.length();
    vector<vector<int>>ans;
    stack<int> zero, one;
    for(i=0; i<n; i++) {
        if(s[i]=='0') {
            if(zero.size()==0) {
                zero.push(ans.size());
                ans.push_back({});
            }
            ans[zero.top()].push_back(i);
            one.push(zero.top());
            zero.pop();
        } else {
            if(one.size()==0) break;
            ans[one.top()].push_back(i);
            zero.push(one.top());
            one.pop();
        }
    }
    if(i<n || zero.size()) {
        cout<<"-1"<<endl;
    } else {
        cout<<ans.size()<<endl;
        for(vector<int> zebra : ans) {
            cout<<zebra.size()<<" ";
            for(int i : zebra) cout<<i+1<<" ";
            cout<<endl;
        }
    }
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

