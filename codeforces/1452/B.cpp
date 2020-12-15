#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin>>n;
	vector<ll> a(n);
	ll total=0, high, have=0;
	for(auto &i : a) {
		cin>>i;
		total+=i;
		have=max(have, i);
	}
	high=(total+n-2)/(n-1);
	high=max(high, have);
	cout<<high*(n-1)-total<<endl;
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

