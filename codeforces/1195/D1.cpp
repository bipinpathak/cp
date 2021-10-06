#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=998244353;
int m=10;

ll power(ll a, ll x) {
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

ll calc(int A, vector<int> &count, int start) {
    ll ans=0;
    vector<int> a;
    while(A) {
        a.push_back(A%10);
        A/=10;
    }
    for(int len=1; len<=m; len++) {
        if(!count[len]) {
            continue;
        }
        ll offer=0;
        int p=start;
        for(int j=0; j<(int)a.size(); j++) {
            offer=(offer+(a[j]*power(10, p))%mod)%mod;
            p++;
            if(len>=j+1+start) {
                p++;
            }
        }
        ans=(ans+(count[len]*offer)%mod)%mod;
    }
    return ans;
}

int len(int a) {
    int ans=0;
    while(a) {
        ans++;
        a/=10;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), count(m+1);
    for(auto &i : a) {
        cin>>i;
        count[len(i)]++;
    }
    ll ans=0;
    for(auto &i : a) {
        ans=(ans+calc(i, count, 0))%mod;
        ans=(ans+calc(i, count, 1))%mod;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

