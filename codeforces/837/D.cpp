#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<vector<int>> num;
    num.push_back({0, 0});
    for(int i=0; i<n; i++) {
        ll x;
        cin>>x;
        int two=0, five=0;
        while(x%2==0) {
            x/=2;
            two++;
        }
        while(x%5==0) {
            x/=5;
            five++;
        }
        num.push_back({two, five});
    }
    vector<vector<int>> dp(k+1, vector<int> (60*k+1, -1));
    dp[0][0]=0;
    for(int curr=1; curr<=n; curr++) {
        for(int used=min(curr, k)-1; used>=0; used--) {
            for(int two=0; two<=60*k; two++) {
                if(dp[used][two]==-1) {
                    continue;
                }
                dp[used+1][two+num[curr][0]]=max(dp[used+1][two+num[curr][0]], dp[used][two]+num[curr][1]);
            }
        }
    }
    int ans=0;
    for(int two=0; two<=60*k; two++) {
        ans=max(ans, min(two, dp[k][two]));
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
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

