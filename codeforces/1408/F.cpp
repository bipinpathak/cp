#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(vector<vector<int>> &ans, vector<int> &a, int d, int &n) {
	if(2*d<=n) {
		for(int i=0; i<n; i+=2*d) {
			for(int j=d-1; j>=0 && i+j+d<n; j--) {
				ans.push_back({a[i+j], a[i+j+d]});
			}
		}
		go(ans, a, 2*d, n);
	}
	return;
}

void solve() {
	int n;
	cin>>n;
	vector<vector<int>> ans;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		a[i]=i+1;
	}
	int p=1;
	while(p<=n) {
		p=p<<1;
	}
	p=p>>1;
	go(ans, a, 1, p);
	reverse(a.begin(), a.end());
	if(n-p>1) {
		go(ans, a, 1, p);
	}
	cout<<ans.size()<<endl;
	for(auto i : ans) {
		for(auto j : i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

