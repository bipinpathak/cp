#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

void solve() {
    string s;
    cin>>s;
    int n=(int)s.size();
    vector<ll> dp(n);
    vector<int> seen(26);
    for(int i=0; i<n; i++) {
        ll sum=0;
        if(!seen[s[i]-'a']) {
            seen[s[i]-'a']=1;
            sum++;
        }
        for(int j=i-2; j>=0; j--) {
            if(j+2<i && s[j+2]==s[i]) {
                break;
            }
            sum=(sum+dp[j])%mod;
        }
        dp[i]=sum;
    }
    ll ans=0;
    for(auto &i : dp) {
        ans=(ans+i)%mod;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

