#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    string s, t;
    cin>>s>>t;
    string ans="YES";
    while(!s.empty() && !t.empty() && s.back()==t.back()) {
        auto c=t.back();
        int count=0;
        while(!t.empty() && t.back()==c) {
            count++;
            t.pop_back();
        }
        while(!s.empty() && s.back()==c) {
            count--;
            s.pop_back();
        }
        if(count<0) {
            ans="NO";
            break;
        }
    }
    if(!s.empty() || !t.empty()) {
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

