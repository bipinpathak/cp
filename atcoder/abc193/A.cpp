#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    double a, b, discount;
    cin>>a>>b;
    discount=(a-b)*100;
    discount/=a;
    cout<<discount<<endl;
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

