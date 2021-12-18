#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int count=0;
    for(auto &i : s) {
        count+=i=='N';
    }
    string ans="NO";
    if(count==0 || count>1) {
        ans="YES";
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

