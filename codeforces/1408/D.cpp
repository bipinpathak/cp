#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int n, m;
	cin>>n>>m;
	vector<pair<int, int>> robbers(n), lights(m);
	for(auto &i : robbers) {
		cin>>i.first>>i.second;
	}
	for(auto &i : lights) {
		cin>>i.first>>i.second;
	}
	int MAXX=1e6+3, ans=MAXX;
	vector<int> yNeeded(MAXX);
	for(auto robber : robbers) {
		for(auto light : lights) {
			if(robber.first<=light.first && robber.second<=light.second) {
				yNeeded[light.first-robber.first]=max(yNeeded[light.first-robber.first], light.second-robber.second+1);
			}
		}
	}
	for(int i=MAXX-2; i>=0; i--) {
		yNeeded[i]=max(yNeeded[i], yNeeded[i+1]);
		ans=min(ans, i+yNeeded[i]);
	}
	cout<<ans<<endl;
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

