#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, k;
	cin>>n>>k;
	ll sum=((n+k-1)/k)*k;
	cout<<(sum+n-1)/n<<endl;
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

