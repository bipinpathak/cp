#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> left, right;
	vector<pair<int, int>> a(n);
	for(auto &i : a) {
		cin>>i.first>>i.second;
		left.push_back(i.first), right.push_back(i.second);
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	int ans=0;
	for(auto seg : a) {
		int offer=n, i=0, j=n-1, mid;
		while(i<j) {
			mid=i+(j-i)/2;
			if(left[mid]>seg.second) {
				j=mid;
			} else {
				i=mid+1;
			}
		}
		if(left[i]<=seg.second) {
			i++;
		}
		offer-=n-i;
		i=0, j=n-1;
		while(i<j) {
			mid=i+(j-i)/2;
			if(right[mid]>=seg.first) {
				j=mid;
			} else {
				i=mid+1;
			}
		}
		if(right[i]>=seg.first) {
			i--;
		}
		offer-=i+1;
		ans=max(ans, offer);
	}
	cout<<n-ans<<endl;
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

