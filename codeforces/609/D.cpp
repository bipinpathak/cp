#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, m, k, s, last=1e6;
	cin>>n>>m>>k>>s;
	vector<ll> dollar(n), pound(n);
	vector<vector<ll>> dollarGadjets, poundGadjets;
	for(auto &i : dollar) {
		cin>>i;
		i=min(last, i);
		last=i;
	}
	last=1e6;
	for(auto &i : pound) {
		cin>>i;
		i=min(last, i);
		last=i;
	}
	for(ll i=0; i<m; i++) {
		ll t, c;
		cin>>t>>c;
		if(t==1) {
			dollarGadjets.push_back({c, i+1});
		} else {
			poundGadjets.push_back({c, i+1});
		}
	}
	sort(dollarGadjets.begin(), dollarGadjets.end());
	sort(poundGadjets.begin(), poundGadjets.end());
	for(ll i=1; i<(ll) dollarGadjets.size(); i++) {
		dollarGadjets[i][0]+=dollarGadjets[i-1][0];
	}
	for(ll i=1; i<(ll) poundGadjets.size(); i++) {
		poundGadjets[i][0]+=poundGadjets[i-1][0];
	}
	vector<vector<ll>> options;
	for(ll i=0; i<=k; i++) {
		if(dollarGadjets.size()>=i && poundGadjets.size()>=k-i) {
			ll dollarNeeded=(i)?dollarGadjets[i-1][0]:0, poundsNeeded=(k-i)?poundGadjets[k-i-1][0]:0;
			options.push_back({i, dollarNeeded, poundsNeeded});
		}
	}
	ll ans=n+1, chosen=-1;
	for(auto distribution : options) {
		ll i=0, j=n-1, mid;
		while(i<j) {
			mid=i+(j-i)/2;
			if(dollar[mid]*distribution[1]+pound[mid]*distribution[2]<=s) {
				j=mid;
			} else {
				i=mid+1;
			}
		}
		if(dollar[i]*distribution[1]+pound[i]*distribution[2]<=s && ans>i+1) {
			ans=i+1;
			chosen=distribution[0];
		}
	}
	if(chosen==-1) {
		cout<<-1<<endl;
	} else {
		cout<<ans<<endl;
		ll dollarDay=1, poundDay=1;
		for(ll i=1; i<ans; i++) {
			if(dollar[i]!=dollar[i-1]) {
				dollarDay=i+1;
			}
			if(pound[i]!=pound[i-1]) {
				poundDay=i+1;
			}
		}
		for(ll i=0; i<chosen; i++) {
			cout<<dollarGadjets[i][1]<<" "<<dollarDay<<endl;	
		}
		for(ll i=0; i<k-chosen; i++) {
			cout<<poundGadjets[i][1]<<" "<<poundDay<<endl;
		}
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
    while(t--) {
        solve();
    }
    return 0;
}

