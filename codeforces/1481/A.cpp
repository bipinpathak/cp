#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x, y;
    string s;
    cin>>x>>y>>s;
    int up=0, down=0, left=0, right=0, currx=0, curry=0;
    for(auto i : s) {
        if(i=='U') {
            up++;
            curry++;
        } else if(i=='D') {
            down++;
            curry--;
        } else if(i=='R') {
            right++;
            currx++;
        } else {
            left++;
            currx--;
        }
    }
    if(currx>x) {
        currx=max(x, currx-right);
    }
    if(currx<x) {
        currx=min(x, currx+left);
    }
    if(curry>y) {
        curry=max(y, curry-up);
    }
    if(curry<y) {
        curry=min(y, curry+down);
    }
    if(currx==x && curry==y) {
        cout<<"YES"<<endl;
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
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

