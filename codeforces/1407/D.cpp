#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, i;
    cin>>n;
    vector<int> h(n), jgl(n, -1), jgr(n, -1), jsl(n , -1), jsr(n, -1) ;
    stack<int> x, y;
    for(int &i : h) cin>>i;
    for(i=0; i<n; i++) {
        while(x.size() && h[x.top()]<=h[i]) {
            jgr[x.top()]=i;
            x.pop();
        }
        x.push(i);
        while(y.size() && h[y.top()]>=h[i]) {
            jsr[y.top()]=i;
            y.pop();
        }
        y.push(i);
    }
    while(x.size()) x.pop();
    while(y.size()) y.pop();
    for(i=n-1; i>=0; i--) {
        while(x.size() && h[i]<=h[x.top()]) {
            jsl[x.top()]=i;
            x.pop();
        }
        x.push(i);
        while(y.size() && h[i]>=h[y.top()]) {
            jgl[y.top()]=i;
            y.pop();
        }
        y.push(i);
    }
    vector<vector<int>> options(n);
    for(i=0; i<n; i++) {
        if(jgl[i]!=-1) options[jgl[i]].push_back(i);
        if(jsl[i]!=-1) options[jsl[i]].push_back(i);
        if(jgr[i]!=-1) options[i].push_back(jgr[i]);
        if(jsr[i]!=-1) options[i].push_back(jsr[i]);
    }
    vector<int> dp(n, INT_MAX);
    dp[0]=0;
    for(i=0; i<n; i++) {
        for(int jump : options[i]) dp[jump]=min(dp[jump], 1+dp[i]);
    }
    cout<<dp[n-1]<<endl;
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

