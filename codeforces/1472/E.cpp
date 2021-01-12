#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct photo{
	int height, width, index;
};

bool custom(photo a, photo b) {
	if(a.width==b.width) {
		return a.height<b.height;
	}
	return a.width<b.width;
}

void solve() {
	int n;
	cin>>n;
	vector<photo> a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i].height>>a[i].width;
		a[i].index=i;
		if(a[i].height>a[i].width) {
			swap(a[i].width, a[i].height);
		}
	}
	sort(a.begin(), a.end(), custom);
	vector<int> ans(n, -1);
	int curr=0, last=0;
	for(int i=1; i<n; i++) {
		if(a[i].width>a[i-1].width) {
			while(last<i) {
				if(a[last].height<a[curr].height) {
					curr=last;
				}
				last++;
			}
		}
		if(a[i].width>a[curr].width && a[i].height>a[curr].height) {
			ans[a[i].index]=a[curr].index;
		}
	}
	for(auto i : ans) {
		if(i>=0) {
			i++;
		}
		cout<<i<<" ";
	}
	cout<<endl;
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

