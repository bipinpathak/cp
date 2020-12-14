#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin>>n;
	map<ll, ll> factors;
	ll i=2, c=n;
	while(c!=1 && i*i<=n) {
		while(c%i==0) {
			factors[i]++;
			c/=i;
		}
		i++;
	}
	ll high=1;
	for(auto i : factors) {
		if(high==1 || i.second>factors[high]) {
			high=i.first;
		}
	}
	cout<<max((ll)1, factors[high])<<endl;
	for(int i=0; i<factors[high]-1; i++) {
		cout<<high<<" ";
		n/=high;
	}
	cout<<n<<endl;
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

