#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> reduced(1e6+1);
void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	map<int, int> count;
	for(auto &i : a) {
		cin>>i;
		count[reduced[i]]++;
	}
	int ans=0, add=0;
	for(auto i : count) {
		if(i.first==1 || i.second%2==0) {
			add+=i.second;
		}
		ans=max(ans, i.second);
	}
	int q;
	cin>>q;
	while(q--) {
		ll w;
		cin>>w;
		cout<<(w?max(ans, add):ans)<<endl;
	}
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
	int n=1e6;
	for(int i=1; i<=n; i++) {
		reduced[i]=i;
	}
	vector<int>  primes(n+1, 1);
	for(ll i=2; i<=n; i++) {
		if(!primes[i]) {
			continue;
		}
		for(ll j=i*i; j<=n; j+=i) {
			primes[j]=0;
			while(reduced[j]%(i*i)==0) {
				reduced[j]/=(i*i);
			}
		}
	}
    while(t--) {
        solve();
    }
    return 0;
}

