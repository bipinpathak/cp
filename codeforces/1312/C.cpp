#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
	int n, k;
	cin>>n>>k;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	sort(a.rbegin(), a.rend());
	set<int> used;
	for(auto &i : a) {
		while(i) {
			ll curr=1;
			int power=0;
			while(i>curr) {
				curr*=k;
				power++;
				if(curr==i || curr*k>i) {
					break;
				}
			}
			if(used.find(power)!=used.end()) {
				return false;
			}
			used.insert(power);
			i-=curr;
		}
	}
    return true;
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
        if(solve()) {
			cout<<"YES"<<endl;	
        } else {
			cout<<"NO"<<endl;
		}
    }
    return 0;
}

