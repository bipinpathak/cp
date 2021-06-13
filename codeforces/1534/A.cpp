#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char> (m)), ans;
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    ans=a;
    for(int i=0; i<n; i++) {
        char curr='R';
        if(i&1) {
            curr='W';
        }
        for(int j=0; j<m; j++) {
            ans[i][j]=curr;
            if(curr=='R') {
                curr='W';
            } else {
                curr='R';
            }
        }
    }
    bool found=true;
    for(int i=0; i<n && found; i++) {
        for(int j=0; j<m && found; j++) {
            if(ans[i][j]!=a[i][j] && a[i][j]!='.') {
                found=false;
            }
        }
    }
    if(!found) {
        found=true;
        for(int i=0; i<n && found; i++) {
            for(int j=0; j<m && found; j++) {
                if(ans[i][j]=='R') {
                    ans[i][j]='W';
                } else {
                    ans[i][j]='R';
                }
                if(ans[i][j]!=a[i][j] && a[i][j]!='.') {
                    found=false;
                }
            }
        }
    }
    if(!found) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(auto &i : ans) {
        for(auto &j : i) {
            cout<<j;
        }
        cout<<endl;
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

