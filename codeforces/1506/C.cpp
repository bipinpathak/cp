#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string a, b;
    cin>>a>>b;
    int n=a.length(), m=b.length(), ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int len=0;
            while(i+len<n && j+len<m && a[i+len]==b[j+len]) {
                len++;
            }
            ans=max(ans, len);
        }
    }
    ans=n+m-2*ans;
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

