#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll go(string &s, int A, int B) {
    ll ans=0, count=0;
    char a='a'+A, b='a'+B;
    for(auto &i : s) {
        if(i==b) {
            ans+=count;
        }
        if(i==a) {
            count++;
        }
    }
    return ans;
}

void solve() {
    string s;
    cin>>s;
    vector<int> f(26);
    for(auto &i : s) {
        f[i-'a']++;
    }
    ll ans=0;
    for(auto &i : f) {
        ans=max(ans, (ll)i);
    }
    for(int i=0; i<26; i++) {
        for(int j=0; j<26; j++) {
            ans=max(ans, go(s, i, j));
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
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

