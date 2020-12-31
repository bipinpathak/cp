#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
	int n;
	cin>>n;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	set<int> seen;
	for(int i=0; i<n; i++) {
		int curr=(a[i]+i)%n;
		curr=(curr+n)%n;
		if(seen.find(curr)!=seen.end()) {
			return false;
		}
		seen.insert(curr);
	}
    return true;
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
        if(solve()) {
			cout<<"YES"<<endl;
        } else {
			cout<<"NO"<<endl;
		}
    }
    return 0;
}

