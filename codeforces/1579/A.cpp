#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    vector<int> count(3);
    for(auto &i : s) {
        count[i-'A']++;
    }
    string ans=(count[1]==count[0]+count[2])?"YES":"NO";
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

