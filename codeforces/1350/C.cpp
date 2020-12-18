#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> factors;

void pre(int n) {
	factors.resize(n+1);
	vector<int> seive(n+1, 1);
	for(ll i=2; i<=n; i++) {
		if(seive[i]) {
			for(ll j=i; j<=n; j+=i) {
				seive[j]=0;
				factors[j].push_back(i);
			}
		}
	}
	return;
}

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	sort(a.begin(), a.end());
	pre(a.back());
	map<int, vector<int>> have;
	for(auto i : a) {
		for(auto j : factors[i]) {
			int count=0;
			while(i%j==0) {
				i/=j;
				count++;
			}
			have[j].push_back(count);
		}
	}
	ll ans=1;
	for(auto i : have) {
		if((int) i.second.size()<n-1) {
			continue;
		}
		sort(i.second.begin(), i.second.end());
		int choice=i.second.front();
		if((int) i.second.size()==n) {
			choice=i.second[1];
		}
		ans*=pow(i.first, choice);
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

