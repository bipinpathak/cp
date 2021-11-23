#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=1e9+7;

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

void solve() {
    int n;
    cin>>n;
    ll ans=power(2, n)-1;
    int m=30;
    vector<int> a(m+1);
    while(n--) {
        int x;
        cin>>x;
        int count=0;
        while((x&1)==0) {
            count++;
            x>>=1;
        }
        a[count]++;
    }
    bool update=true;
    while(update) {
        update=false;
        for(int i=0; i<m; i++) {
            a[i]=a[i+1];
            if(a[i]) {
                update=true;
            }
        }
        a[m]=0;
        if(a[0]) {
            int odd=a[0], even=-odd;
            for(auto i : a) {
                even+=i;
            }
            ans=(ans-power(2, odd+even-1))%mod;
        }
    }
    if(ans<0) {
        ans+=mod;
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

