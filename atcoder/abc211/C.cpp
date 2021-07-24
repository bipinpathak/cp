#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

void solve() {
    string s;
    cin>>s;
    int n=8;
    vector<ll> dp(n);
    map<char, int> index;
    string pattern="chokudai";
    for(int i=0; i<n; i++) {
        index[pattern[i]]=i;
    }   
    for(auto i : s) {
        if(index.count(i)) {
        int curr=index[i];
        if(curr==0) {
            dp[curr]++;
        } else {
            dp[curr]+=dp[curr-1];
        }
        dp[curr]%=mod;
        }
    }
    cout<<dp[n-1]<<endl;
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

