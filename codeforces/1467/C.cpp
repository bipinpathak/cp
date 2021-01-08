#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n1, n2, n3;
	cin>>n1>>n2>>n3;
	vector<ll> a(n1), b(n2), c(n3), remove, sumRemove;
	ll ans=0, low=1e9, sum=0;
	for(auto &i : a) {
		cin>>i;
		sum+=i;
		low=min(low, i);
	}
	ans+=sum;
	sumRemove.push_back(sum);
	remove.push_back(low);
	low=1e9;
	sum=0;
	for(auto &i : b) {
		cin>>i;
		sum+=i;
		low=min(low, i);
	}
	ans+=sum;
	sumRemove.push_back(sum);
	remove.push_back(low);
	low=1e9;
	sum=0;
	for(auto &i : c) {
		cin>>i;
		sum+=i;
		low=min(low, i);
	}
	ans+=sum;
	sumRemove.push_back(sum);
	sum=0;
	remove.push_back(low);
	low=1e9;
	sort(remove.begin(), remove.end());
	sort(sumRemove.begin(), sumRemove.end());
	ans-=min(2*(remove[0]+remove[1]), 2*sumRemove[0]);
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

