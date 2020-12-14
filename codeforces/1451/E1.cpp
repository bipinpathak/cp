#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, a, know=0;
	cin>>n;
	vector<ll> with1(n+1), ans(n+1);
	for(ll i=2; i<=n; i++) {
		cout<<"XOR 1 "<<i<<endl;
		cin>>with1[i];
	}
	map<ll, ll> index;
	for(ll i=1; i<=n; i++) {
		if(index.find(with1[i])==index.end()) {
			index[with1[i]]=i;
		} else {
			cout<<"AND "<<index[with1[i]]<<" "<<i<<endl;
			cin>>ans[i];
			know=i;
			break;
		}
	}
	if(!know) {
		for(ll i=2; i<=n; i++) {
			if(with1[i]!=n-1) {
				cout<<"AND 1 "<<i<<endl;
				cin>>a;
				ans[1]+=(n-1-with1[i])&a;
				know=i;
				break;
			}
		}
		for(ll i=1; i<=n; i++) {
			if(with1[know]+with1[i]==n-1) {
				cout<<"AND 1 "<<i<<endl;
				cin>>a;
				ans[1]+=(n-1-with1[i])&a;
				break;
			}
		}
		know=1;
	}
	for(ll i=1; i<=n; i++) {
		ans[i]=with1[i]^with1[know]^ans[know];
	}
	cout<<"! ";
	for(ll i=1; i<=n; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

