#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
	int n, m;
	cin>>n>>m;
	vector<ll> memory(n), one, two;
	for(auto &i : memory) {
		cin>>i;
	}
	for(int i=0; i<n; i++) {
		int points;
		cin>>points;
		if(points==1) {
			one.push_back(memory[i]);
		} else {
			two.push_back(memory[i]);
		}
	}
	sort(one.rbegin(), one.rend());
	sort(two.rbegin(), two.rend());
	ll sum=0;
	for(auto &i : two) {
		i+=sum;
		sum=i;
	}
	int usedOne=0, ans=-1;
	ll oneContri=0;
	for(int usedTwo=(int)two.size(); usedTwo>=0; usedTwo--) {
		ll twoContri=0;
		if(usedTwo) {
			twoContri=two[usedTwo-1];
		}
		while(usedOne<(int)one.size() &&  twoContri+oneContri<m) {
			oneContri+=one[usedOne];
			usedOne++;
		}
		if(twoContri+oneContri<m) {
			break;
		}
		if(ans==-1) {
			ans=usedOne+2*usedTwo;
		} else {
			ans=min(ans, usedOne+2*usedTwo);
		}
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

