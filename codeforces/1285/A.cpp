#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int l=0, r=0;
    for(auto i : s) {
        if(i=='L') {
            l--;
        } else {
            r++;
        }
    }
    cout<<r-l+1<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

