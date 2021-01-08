#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void go(vector<int> &a, vector<int> &b, int key, vector<set<int>> &active) {
	for(int i=0; i<(int)a.size(); i++) {
		set<int> update;
		for(auto j : active[i]) {
			if(((a[i]&b[j])&key)==0) {
				update.insert(j);
			}
		}
		active[i]=update;
	}
	return;
}

void solve() {
	int n, m, ans=0;
	cin>>n>>m;
	vector<int> a(n), b(m);
	for(auto &i : a) {
		cin>>i;
	}
	for(auto &i : b) {
		cin>>i;
	}
	vector<set<int>> active(n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			active[i].insert(j);
		}
	}
	int key=1<<8;
	while(key) {
		int possible=true;
		for(int i=0; i<n && possible; i++) {
			possible=false;
			for(auto j : active[i]) {
				if(((a[i]&b[j])&key)==0) {
					possible=true;
					break;
				}
			}
		}
		if(possible) {
			go(a, b, key, active);
		} else {
			ans+=key;
		}
		key=key>>1;
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

