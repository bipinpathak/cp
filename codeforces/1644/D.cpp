#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=998244353;

ll power(ll a, ll x) {
    a%=mod;
    if(a==0) {
        return a;
    }
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%mod;
		}
		x=x>>1;
		a=(a*a)%mod;
	}
	return ans;
}

void solve() {
    int n, m, k, q;
    cin>>n>>m>>k>>q;
    map<int, int> row, col;
    for(int i=1; i<=q; i++) {
        int x, y;
        cin>>x>>y;
        x--, y--;
        row[x]=i;
        col[y]=i;
    }
    int allRows=0, allColumns=0;
    if(row.size()==n) {
        allRows=q;
        for(auto &[x, i] : row) {
            allRows=min(allRows, i);
        }
    }
    if(col.size()==m) {
        allColumns=q;
        for(auto &[y, i]: col) {
            allColumns=min(allColumns, i);
        }
    }
    set<int> left;
    for(auto &[x, i] : row) {
        if(i>=allColumns) {
            left.insert(i);
        }
    }
    for(auto &[y, i]: col) {
        if(i>=allRows) {
            left.insert(i);
        }
    }
    left.erase(0);
    ll ans=power(k, left.size());
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

