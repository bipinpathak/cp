#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int k;
	cin>>k;
	cout<<3<<" "<<2<<endl;
	cout<<((1<<18)-1)<<" "<<((1<<18)-1-k)<<endl;
	cout<<k<<" "<<((1<<18)-1)<<endl;
	cout<<0<<" "<<k<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

