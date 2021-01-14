#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int calc(int a, int b, int c, vector<vector<int>> &points) {
	int ans=0;
	for(int i=0; i<5; i++) {
		ans+=(points[b][i]-points[a][i])*(points[c][i]-points[a][i]);
	}
	return ans;
}
void solve() {
	int n;
	cin>>n;
	vector<vector<int>> points(n, vector<int> (5));
	vector<int> ans;
	for(auto &i : points) {
		for(auto &j : i) {
			cin>>j;
		}
	}
	for(int i=0; i<n; i++) {
		bool good=true;
		for(int j=0; j<n && good; j++) {
			for(int k=j+1; k<n && good; k++) {
				if(j==i || k==i) {
					continue;
				}
				if(calc(i, j, k, points)>0) {
					good=false;
				}
			}
		}
		if(good) {
			ans.push_back(i+1);
		}
	}
	cout<<ans.size()<<endl;
	for(auto i : ans) {
		cout<<i<<endl;
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

