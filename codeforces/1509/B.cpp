#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int t=0, m=0;
    int done=0;
    for(auto i: s) {
        if(i=='T') {
            if(m) {
                m--;
                done++;
            } else {
                t++;
            }
        } else {
            if(t) {
                t--;
                m++;
            } else if(done) {
                done--;
                m+=2;
            } else {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    string ans="YES";
    if(m || t) {
        ans="NO";
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

