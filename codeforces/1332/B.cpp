#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	map<int, int> index;
	int count=0;
	for(auto &i : a) {
		cin>>i;
		for(auto j : primes) {
			if(i%j==0) {
				if(index.find(j)==index.end()) {
					count++;
					index[j]=count;
				}
				i=index[j];
				break;
			}
		}
	}
	cout<<count<<endl;
	for(auto i : a) {
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

