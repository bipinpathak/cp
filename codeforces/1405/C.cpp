#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k, i;
    string s, ans="YES";
    cin>>n>>k>>s;
    vector<char> f(k, '?');
    for(i=0; i<n && ans=="YES"; i++) {
        if(f[i%k]=='?') f[i%k]=s[i];
        else if(s[i]!='?' && f[i%k]!=s[i]) ans="NO";
    }
    int one=0, zero=0;
    if(ans=="YES") {
        for(char c : f) {
            if(c=='1') one++;
            else if(c=='0') zero++;
        }
        if(one>k/2 || zero>k/2) ans="NO";
    }
    cout<<ans<<endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

