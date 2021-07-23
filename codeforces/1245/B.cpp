#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, a, b, c;
    string s;
    cin>>n>>a>>b>>c>>s;
    string ans(n, 'X');
    for(int i=0; i<n; i++) {
        if(s[i]=='R' && b) {
            ans[i]='P';
            b--;
        }
        if(s[i]=='P' && c) {
            ans[i]='S';
            c--;
        }
        if(s[i]=='S' && a) {
            ans[i]='R';
            a--;
        }
    }
    int win=0;
    for(auto &i : ans) {
        if(i=='X') {
            if(a) {
                i='R';
                a--;
            } else if(b) {
                i='P';
                b--;
            } else {
                i='S';
                c--;
            }
        } else {
            win++;
        }
    }
    if(win>=(n+1)/2) {
        cout<<"YES"<<endl<<ans<<endl;
    } else {
        cout<<"NO"<<endl;
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

