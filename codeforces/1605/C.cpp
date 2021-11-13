#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int m=7;
    m=min(m, n);
    for(int k=2; k<=m; k++) {
        vector<int> f(3);
        for(int i=0; i<n; i++) {
            f[s[i]-'a']++;
            if(i-k+1>=0) {
                if(f[0]>f[1] && f[0]>f[2]) {
                    cout<<k<<endl;
                    return;
                }
                f[s[i-k+1]-'a']--;
            }
        }
    }
    cout<<-1<<endl;
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

