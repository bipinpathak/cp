#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll x, ll p) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%p;
		}
		x=x>>1;
		a=(a*a)%p;
	}
	return ans;
}

void solve() {
    int m;
    cin>>m;
    vector<int> a(m);
    map<int, int> count;
    for(auto &i : a) {
        cin>>i;
        count[i]++;
    }
    ll total=1, n=1, ans=1, root=1, p=1e9+7;
    bool square=true, halfed=false;
    for(auto [f, c] : count) {
        n=(n*power(f, c, p))%p;
        if(square && c%2) {
            square=false;
        }
        if(square) {
            root=(root*power(f, c/2, p))%p; 
        }
        if(!halfed && c%2) {
            total=(total*((c+1)/2))%(p-1);
            halfed=true;
        } else {
            total=(total*(c+1))%(p-1);
        }
    }
    if(square) {
        ans=power(root, total, p);
    }  else {
        ans=power(n, total, p);
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
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

