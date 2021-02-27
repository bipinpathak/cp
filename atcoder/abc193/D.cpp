#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> fac;
ll p=1e9+7;
ll power(ll a, ll x) {
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
void pre(int n) {
	ll x=1;
	fac.push_back(x);
	for(ll i=1; i<=n; i++) {
		x=(x*i)%p;
		fac.push_back(x);
	}
	return;
}

bool win(vector<int> &a, vector<int> &b) {
    ll asum=0, bsum=0;
    for(ll i=1; i<10; i++) {
        asum+=i*power(10, a[i]);
        bsum+=i*power(10, b[i]);
    }
    return asum>bsum;
}

ll count(int &me, int &you, vector<int> original) {
    ll ans;
    ans=original[me];
    original[me]--;
    ans=ans*original[you];
    return ans;
}

void solve() {
    ll k;
    string s, t;
    cin>>k>>s>>t;
    vector<int> a(10), b(10), original(10);
    for(int i=0; i<4; i++) {
        a[s[i]-'0']++;
        b[t[i]-'0']++;
    }
    for(int i=1; i<10; i++) {
        original[i]=k-a[i]-b[i];
    }
    ll good=0, total=(9*k-8)*(9*k-9);
    for(int me=1; me<10; me++) {
        for(int you=1; you<10; you++) {
            a[me]++;
            b[you]++;
            if(a[me]+b[me]<=k && a[you]+b[you]<=k && win(a, b)) {
                good+=count(me, you, original); 
            } 
            a[me]--;
            b[you]--;
        }
    }
    double ans=(double)good/(double)total;
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

