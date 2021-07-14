#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string p, h;
    cin>>p>>h;
    vector<int> pc(26);
    for(auto i : p) {
        pc[i-'a']++;
    }
    int n=(int)p.size(), m=(int)h.size();
    vector<vector<int>> f(m, vector<int> (26));
    for(int i=0; i<m; i++) {
        if(i) {
            f[i]=f[i-1];
        }
        f[i][h[i]-'a']++;
    }
    string ans="NO";
    for(int i=n-1; i<m && ans=="NO"; i++) {
        vector<int> cur=f[i];
        if(i>n-1) {
            for(int j=0; j<26; j++) {
                cur[j]-=f[i-n][j];
            }
        }
        if(cur==pc) {
            ans="YES";
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

