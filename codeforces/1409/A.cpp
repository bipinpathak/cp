#include <bits/stdc++.h>
using namespace std;
void solve() {
    int a, b;
    cin>>a>>b;
    cout<<(abs(a-b)+9)/10<<endl;
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

