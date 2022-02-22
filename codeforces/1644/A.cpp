#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    set<char> seen;
    string ans="YES";
    for(auto &i : s) {
        if(i>='a') {
            seen.insert(i);
        } else {
            i+=32;
            if(!seen.count(i)) {
                ans="NO";
                break;
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

