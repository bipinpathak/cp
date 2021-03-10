#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    cout<<fixed<<setprecision(15);
    int n;
    cin>>n;
    vector<int> x, y;
    for(int i=0; i<2*n; i++) {
        int a, b;
        cin>>a>>b;
        a=abs(a);
        b=abs(b);
        if(a) {
            x.push_back(a);
        } else {
            y.push_back(b);
        }
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long double ans=0;
    for(int i=0; i<n; i++) {
        ll a=x[i], b=y[i];
        ans+=sqrtl(a*a+b*b);
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

