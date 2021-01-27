#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n=500;
vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1));
vector<int> a(n+1);

void merge(vector<int> &x, vector<int> &y) {
	for(auto i : y) {
		while(x.size() && x.back()==i) {
			i++;
			x.pop_back();
		}
		x.push_back(i);
	}
	return;
}

void build(int left, int right) {
	for(int i=left; i<=right; i++) {
		dp[left][right].push_back(a[i]);
	}
	for(int mid=left; mid<right; mid++) {
		if(dp[left][mid].size()==0) {
			build(left, mid);
		}
		if(dp[mid+1][right].size()==0) {
			build(mid+1, right);
		}
		int offer=(int)dp[left][mid].size()+(int)dp[mid+1][right].size();
		if(dp[left][mid].back()==dp[mid+1][right].front()) {
			offer--;
		}
		if((int)dp[left][right].size()>offer) {
			while(dp[left][right].size()) {
				dp[left][right].pop_back();
			}
			merge(dp[left][right], dp[left][mid]);
			merge(dp[left][right], dp[mid+1][right]);
		}
	}
	return;
}

int fetch(int left, int right) {
	if(dp[left][right].size()==0) {
		build(left, right);
	}
	return (int)dp[left][right].size();
}

void solve() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	cout<<fetch(1, n)<<"\n";
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

