#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, one=0, zero=0;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a ) {
		string s;
		cin>>s;
		i=s.length();
		for(auto j : s) {
			if(j=='1') {
				one++;
			} else {
				zero++;
			}
		}
	}
	int odd=0;
	for(auto i : a) {
		odd+=i%2;
	}
	if(one%2 && odd) {
		one--;
		odd--;
	}
	if(zero%2 && odd) {
		zero--;
		odd--;
	}
	int ans=n;
	if(one%2 || zero%2 || odd%2) {
		ans--;
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
    while(t--) {
        solve();
    }
    return 0;
}

