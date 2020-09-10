#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, xlow=-1e5, xhigh=1e5, ylow=-1e5, yhigh=1e5, x, y, left, up, right, down, possible=1;
    cin>>n;
    while(n--) {
        cin>>x>>y>>left>>up>>right>>down;
        if(!up) yhigh=min(yhigh, y);
        if(!down) ylow=max(ylow, y);
        if(!right) xhigh=min(xhigh, x);
        if(!left) xlow=max(xlow, x);
    }
    if(xlow>xhigh || ylow>yhigh) possible=0;
    cout<<possible<<" ";
    if(possible) {
        cout<<xlow<<" "<<ylow;
    }
    cout<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

