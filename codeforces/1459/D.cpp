#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct jar{
    int capacity, filled;
};

void solve() {
    int n;
    cin>>n;
    vector<jar> a(n);
    int totalWater=0, totalCapacity=0;
    for(auto &i : a) {
        cin>>i.capacity>>i.filled;
        totalWater+=i.filled;
        totalCapacity+=i.capacity;
    }
    vector<vector<int>> dp(n+1, vector<int> (totalCapacity+1, -1));
    dp[0][0]=0;
    for(int i=0; i<n; i++) {
        for(int use=i+1; use; use--) {
            for(int curr=a[i].capacity; curr<=totalCapacity; curr++) {
                if(dp[use-1][curr-a[i].capacity]==-1) {
                    continue;
                }
                dp[use][curr]=max(dp[use][curr], dp[use-1][curr-a[i].capacity]+a[i].filled);
            }
        }
    }
    for(int use=1; use<=n; use++) {
        double ans=0;
        for(int total=0; total<=totalCapacity; total++) {
            if(dp[use][total]==-1) {
                continue;
            }
            ans=max(ans, min((double)total, (double)(dp[use][total]+totalWater)/(double)2));
        }
        cout<<ans<<" ";
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
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

