#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fetch(ll total, ll n, vector<vector<ll>> &store, vector<ll> &happy) {
	if(store[total][n]==-1) {
		ll m=happy.size();
		store[total][n]=0;
		if(n==1) {
			if(total>m) {
				store[total][n]=-1e9;
			} else if(total==0) {
				store[total][n]=0;
			} else {
				store[total][n]=happy[total-1];
			}
		} else {
			for(ll i=0; i<=min(total, m); i++) {
				store[total][n]=max(store[total][n], fetch(total-i, n-1, store, happy)+(i?happy[i-1]:0));
			}
		}
	}
	return store[total][n];
}

void solve() {
	ll n, k;
	cin>>n>>k;
	vector<ll> cards, fav, happy(k);
	map<ll, ll> index;
	for(ll i=0; i<k*n; i++) {
		ll x;
		cin>>x;
		if(index.find(x)==index.end()) {
			index[x]=cards.size();
			cards.push_back(0);
		}
		cards[index[x]]++;
	}
	fav.resize(cards.size(), 0);
	for(ll i=0; i<n; i++) {
		ll x;
		cin>>x;
		if(index.find(x)==index.end()) {
			index[x]=cards.size();
			cards.push_back(0);
			fav.push_back(0);
		}
		fav[index[x]]++;
	}
	for(auto &i : happy) {
		cin>>i;
	}
	vector<vector<ll>> store(n*k+1, vector<ll> (n+1, -1));
	ll ans=0;
	for(ll i=0; i<(ll)cards.size(); i++) {
		if(cards[i]==0 || fav[i]==0) {
			continue;
		}
		if(cards[i]>=fav[i]*k) {
			ans+=happy[k-1]*fav[i];
		} else {
			ans+=fetch(cards[i], fav[i], store, happy);
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
    while(t--) {
        solve();
    }
    return 0;
}

