#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    string s, t;
    cin>>n>>m>>s>>t;
    vector<int> high(m), low(m);
    int index=0;
    for(int i=0; i<n && index<m; i++) {
        if(s[i]==t[index]) {
            low[index]=i;
            index++;
        }
    }
    index=m-1;
    for(int i=n-1; i>=0 && index>=0; i--) {
        if(s[i]==t[index]) {
            high[index]=i;
            index--;
        }
    }
    int ans=0;
    for(int i=0; i+1<m; i++) {
        ans=max(ans, high[i+1]-low[i]);
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

