#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void go(int n, set<int> &factors) {
	for(int i=1; i*i<=n; i++) {
		if(n%i==0) {
			factors.insert(i);
			factors.insert(n/i);
		}
	}
	return;
}

bool solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> a(n);
	while(m--) {
		int l, r, len;
		cin>>l>>r;
		len=r-l;
		if(l>r) {
			len+=n;
		}
		a[l-1].push_back(len);
		a[r-1].push_back(n-len);
	}
	set<int> factors;
	go(n, factors);
	factors.erase(n);
	for(auto &i : a) {
		sort(i.begin(), i.end());
	}
	for(auto p : factors) {
		int i;
		for(i=0; i<n; i++) {
			if(a[i]!=a[(i+p)%n]) {
				break;
			}
		}
		if(i==n) {
			return 1;
		}
	}
    return 0;
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
        if(solve()) {
			cout<<"Yes"<<endl;
        } else {
			cout<<"No"<<endl;
		}		
    }
    return 0;
}

