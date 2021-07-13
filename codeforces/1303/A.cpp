#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int n=(int)s.size();
    int ans=0;
    for(auto i : s) {
        ans+=i=='0';
    }
    for(int i=0; i<n && s[i]=='0'; i++) {
        ans--;
    }
    for(int i=n-1; i>=0 && s[i]=='0'; i--) {
        ans--;
    }
    ans=max(ans, 0);
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

