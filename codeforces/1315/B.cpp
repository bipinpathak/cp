#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int a, b, p;
    string s;
    cin>>a>>b>>p>>s;
    int n=(int)s.size();
    vector<ll> cost(n);
    char last='c';
    for(int i=n-2; i>=0; i--) {
        cost[i]=cost[i+1];
        if(s[i]!=last) {
            cost[i]+=s[i]=='A'?a:b;
            last=s[i];
        }
    }
    int ans=0;
    while(ans<n && cost[ans]>p) {
        ans++;
    }
    ans++;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

