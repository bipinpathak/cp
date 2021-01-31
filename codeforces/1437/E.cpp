#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int LIS(vector<int> &active, int low, int high) {
	int n=(int)active.size();
	vector<int> store(n+2, 1e9+1);
	store[0]=-1e9;
	reverse(active.begin(), active.end());
	while(!active.empty()) {
		if(active.back()>=low && active.back()<=high) {
			int j=upper_bound(store.begin(), store.end(), active.back())-store.begin();	
			if(store[j-1]<=active.back() && active.back()<=store[j]) {
				store[j]=active.back();
			}
		}
		active.pop_back();
	}
	for(int i=n; i; i--) {
		if(store[i]<1e9+1) {
			return i;
		}
	}
	return 0;
}

void solve() {
	int n, k;
	cin>>n>>k;
	vector<int> a(n), fixed(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
		a[i]-=i;
	}
	while(k--) {
		int x;
		cin>>x;
		x--;
		fixed[x]++;
	}
	vector<int> active;
	int ans=n, low=-1e9, high=-1e9;
	for(int i=0; i<n; i++) {
		if(!fixed[i]) {
			active.push_back(a[i]);
			continue;
		}
		ans--;
		low=high;
		high=a[i];
		if(low>high) {
			ans=-1;
			break;
		}
		if(!active.empty()) {
			ans-=LIS(active, low, high);
		}
	}
	if(!active.empty() && ans!=-1) {
		low=high;
		high=1e9;
		ans-=LIS(active, low, high);
	}
	cout<<ans<<endl;
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

