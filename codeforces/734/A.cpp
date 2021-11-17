#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    int a=0, d=0;
    while(n--) {
        char m;
        cin>>m;
        if(m=='A') {
            a++;
        } else {
            d++;
        }
    }
    string ans="Friendship";
    if(a>d) {
        ans="Anton";
    } else if(d>a) {
        ans="Danik";
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

