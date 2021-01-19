#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> primes;
void solve() {
	int d;
	cin>>d;
	ll ans=1;
	int count=0, last=1;
	for(auto i : primes) {
		if(i-last>=d) {
			ans*=i;
			last=i;
			count++;
		}
		if(count==2) {
			break;
		}
	}
	cout<<ans<<endl;
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
	vector<int> seive(1e6);
	primes.push_back(1);
	for(ll i=2; i<1e6; i++) {
		if(seive[i]) {
			continue;
		}
		primes.push_back(i);
		for(ll j=i*i; j<1e6; j+=i) {
			seive[j]=1;
		}
	}
    while(t--) {
        solve();
    }
    return 0;
}

