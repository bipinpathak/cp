#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int n=(int)s.size(), ans=0;
    for(int i=0; i<n; i++) {
        int curr=0, extra=0;
        for(int j=i; j<n; j++) {
            if(s[j]==')') {
                curr--;
            } else if(s[j]=='(') {
                curr++;
            } else {
                extra++;
            }
            if(curr-extra<0 && extra>0) {
                curr++;
                extra--;
            }
            if(curr-extra<0) {
                break;
            }
            if(((j-i)&1) && extra>=curr) {
                ans++;
            }
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

