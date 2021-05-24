#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i :a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    int ans=0, high=a[0];
    for(int i=0; i<n; i++) {
        high=max(high, a[i]);
        if(high>0) {
            break;
        } else if(high<=0) {
            ans=i+1;
        }
    }
    vector<int> dp(n);
    int low=0;
    for(int i=0; i<n; i++) {
        if(i) {
            dp[i]=max(dp[i], dp[i-1]);
        }
        while(low<=i && a[i]-a[low]>=high) {
            low++;
        }
        dp[i]=1+(low?dp[low-1]:0);
        ans=max(ans, dp[i]);
        if(a[i]==high) {
            break;
        }
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
    auto start=clock();
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

