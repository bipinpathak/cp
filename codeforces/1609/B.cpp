#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, q;
    string s;
    cin>>n>>q>>s;
    int curr=0;
    for(int i=0; i+2<n; i++) {
        if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c') {
            curr++;
        }
    }
    while(q--) {
        int pos;
        char c;
        cin>>pos>>c;
        pos--;
        for(int i=max(0, pos-2); i<=pos && i+2<n; i++) {
            if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c') {
                curr--;
            }
        }
        s[pos]=c;
        for(int i=max(0, pos-2); i<=pos && i+2<n; i++) {
            if(s[i]=='a' && s[i+1]=='b' && s[i+2]=='c') {
                curr++;
            }
        }
        cout<<curr<<endl;
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
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

