#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n, q;
    string s;
    cin>>n>>q>>s;
    vector<vector<int>> prefix(n+1, vector<int> (26));
    for(int i=1; i<=n; i++) {
        prefix[i]=prefix[i-1];
        prefix[i][s[i-1]-'a']++;
    }
    while(q--) {
        int l, r;
        cin>>l>>r;
        int ans=0;
        for(int i=0; i<26; i++) {
            ans+=(i+1)*(prefix[r][i]-prefix[l-1][i]);
        }
        cout<<ans<<endl;
    }
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

