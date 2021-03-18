#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int x;
    cin>>x;
    cout<<(x+6)/7<<endl; 
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

