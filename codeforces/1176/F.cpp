#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(int index, vector<ll> curr, vector<vector<ll>> &dp) {
    sort(curr.rbegin(), curr.rend()); 
    int n=(int)curr.size();
    for(int prev=0; prev<10; prev++) {
        if(dp[index-1][prev]==-1) {
            continue;
        }
        int next=(prev+n)%10;
        ll sum=0;
        for(auto i : curr) {
            sum+=i;
        }
        if(next<prev) {
            sum+=curr.front();
        }
        dp[index][next]=max(dp[index][next], dp[index-1][prev]+sum);
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<vector<ll>>> options(n+1, vector<vector<ll>> (3));
    for(int i=1; i<=n; i++) {
        int k;
        cin>>k;
        while(k--) {
            ll c, d;
            cin>>c>>d;
            c--;
            options[i][c].push_back(d);
        }
        for(auto &j : options[i]) {
            sort(j.rbegin(), j.rend());
        }
    }
    vector<vector<ll>> dp(n+1, vector<ll> (10, -1));
    dp[0][0]=0;
    for(int i=1; i<=n; i++) {
        dp[i]=dp[i-1];
        vector<ll> curr;
        for(int j=0; j<3 && j<(int)options[i][0].size(); j++) {
            curr.push_back(options[i][0][j]);
            go(i, curr, dp);
        }
        if(!options[i][1].empty()) {
            go(i, {options[i][1].front()}, dp); 
            if(!options[i][0].empty()) {
                go(i, {options[i][0].front(), options[i][1].front()}, dp);
            }
        }
        if(!options[i][2].empty()) {
            go(i, {options[i][2].front()}, dp);
        }
    }
    ll ans=0;
    for(auto i :dp[n]) {
        ans=max(ans, i);
    }
    cout<<ans<<endl;
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

