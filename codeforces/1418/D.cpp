#include <bits/stdc++.h>
using namespace std;
using ll = long long;
set<int> piles;
map<int, int> gaps;

void add(int x, int y) {
	gaps[y-x]++;
	return;
}

void remove(int x, int y) {
	gaps[y-x]--;
	if(!gaps[y-x]) {
		gaps.erase(y-x);
	}
	return;
}

void solve() {
	int n, q;
	cin>>n>>q;
	while(n--) {
		int x;
		cin>>x;
		piles.insert(x);
	}
	int last=0;
	for(auto i : piles) {
		if(last) {
			gaps[i-last]++;
		}
		last=i;
	}
	cout<<*piles.rbegin()-*piles.begin()-(gaps.size()?gaps.rbegin()->first:0)<<endl;
	while(q--) {
		int t, x, low=0, high=0;
		cin>>t>>x;
		if(t) {
			auto big=piles.upper_bound(x);
			if(big!=piles.end()) {
				high=*big;
			}
			if(big!=piles.begin()) {
				big--;
				low=*big;
			}
			if(high && low) {
				remove(low, high);
			}
			if(high) {
				add(x, high);

			}
			if(low) {
				add(low, x);
			}
			piles.insert(x);
		} else {
			piles.erase(x);
			if((int)piles.size()==0) {
				gaps.clear();
				cout<<0<<endl;
				continue;
			}
			auto big=piles.upper_bound(x);
			if(big!=piles.end()) {
				high=*big;
			}
			if(big!=piles.begin()) {
				big--;
				low=*big;
			}
			if(high && low) {
				add(low, high);
			}
			if(high) {
				remove(x, high);
			}
			if(low) {
				remove(low, x);
			}
		}
		cout<<*piles.rbegin()-*piles.begin()-(gaps.size()?gaps.rbegin()->first:0)<<endl;
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

